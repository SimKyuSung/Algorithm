// 테스트용 STL
// #include <iostream>
// #include <vector>
// using namespace std;

/*
	buy(CAR car): car 를 구매하여 재고에 넣는다.
	sell(): filter 의 조건에 해당하는 차를 판매하여 재고에서 비운다.
	        해당 판매의 번호를 지정하여 반환한다. 판매 번호는 중복될 수 없다.

	refund(int order_number): 해당 판매 번호에 대한 재고를 복원(반환)한다.
	empty(): 남아 있는 차의 수를 반환한다.
	나머지는 main 문을 읽고 문제를 해석하여 PASS 를 받으시오.
*/

struct CAR
{
	int age;       // 0 ~ 19
	int passenger; // 2 ~ 12
	int engine;    // 1000 ~ 4999
	int price;     // 10000 ~ 39999
};

struct FILTER
{
	int from;
	int to;
};

static const int age_range = 20;
static const int passenger_range = 11;

// static vector<CAR> inventory[age_range][passenger_range];

// 환불 할 때 기록을 안해서 잘못 측정된듯.
// test result(10 test case) = 997
// int vector_max_size_test = 0;
static const int vector_max_size = 1500;

static CAR inventory[age_range][passenger_range][vector_max_size];
static int inventorySize[age_range][passenger_range];


// car 를 구매하여 재고에 넣는다.
void buy(CAR car)
{
	// inventory[car.age][car.passenger - 2].push_back(car);
	// vector_max_size_test = max(vector_max_size_test, (int)inventory[car.age][car.passenger - 2].size());
	inventory[car.age][car.passenger - 2][inventorySize[car.age][car.passenger - 2]++] = car;
}

// filter 의 조건에 해당하는 차를 판매하여 재고에서 비운다.
// 해당 판매의 번호를 지정하여 반환한다. 판매 번호는 중복될 수 없다
// how to search fast?
FILTER filter_age;
FILTER filter_passenger;
FILTER filter_engine;
FILTER filter_price;

void filter_by_age(int from, int to)
{
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}
	filter_age.from = from;
	filter_age.to = to;
}

void filter_by_passenger(int from, int to)
{
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}
	filter_passenger.from = from;
	filter_passenger.to = to;
}

void filter_by_engine(int from, int to)
{
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}
	filter_engine.from = from;
	filter_engine.to = to;
}

void filter_by_price(int from, int to)
{
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}
	filter_price.from = from;
	filter_price.to = to;
}

// test result(10 test case) = 6054
// int max_order_car_size = 0;
static const int max_order_car = 10000;

int order_number = 0;
// static vector<CAR> order_car_list[15000];

// 전체 오더 기록은 너무 많음.
// 10% 확률로 메모리됨.
// 100번을 초과 하는 판매에서 메모리된 판매기록이 나올 확률은?
// 0.00002656139 (0.0026%)
static CAR order_car_list[100][max_order_car];
static int order_car_list_size[100];

int sell(void)
{
	int order_size = 0;
	// vector <CAR> order;

	for (int i = filter_age.from; i <= filter_age.to; ++i) {
		for (int j = filter_passenger.from - 2; j <= filter_passenger.to - 2; ++j) {
			// auto& cars = inventory[i][j];
			// for (auto it = cars.begin(); it != cars.end(); ++it) {
			// 	if (it->engine >= filter_engine.from && it->engine <= filter_engine.to &&
			// 		it->price >= filter_price.from && it->price <= filter_price.to) {
			// 		order.push_back(*it);
			// 		it = cars.erase(it);
			// 		--it;
			// 	}
			// }
			for (int k = 0; k < inventorySize[i][j]; ++k) {
				CAR& car = inventory[i][j][k];
				if (car.engine >= filter_engine.from &&
					car.engine <= filter_engine.to &&
					car.price >= filter_price.from &&
					car.price <= filter_price.to) {
					order_car_list[order_number % 100][order_size++] = car;

					// 예쁘게 삭제하기 (순서 유지 필요 없음, 맨마지막 값을 현재 위치로 옮기고 사이즈 감소)
					inventory[i][j][k] = inventory[i][j][inventorySize[i][j] - 1];
					--inventorySize[i][j];
					--k; // Adjust index after removal
				}
			}
		}
	}

	// cout << "sell and car count: " << empty() << endl;

	if (order_size == 0) {
		return -1; // No car found matching the filter criteria
	}
	// max_order_car_size = max(max_order_car_size, (int)order.size());
	// order_car_list[order_number] = order;
	order_car_list_size[order_number % 100] = order_size;
	return order_number++;
}

// 남아 있는 차의 수를 반환한다. (테스트용)
// int emptyTest(void)
// {
// 	int car_count = 0;
// 	for (int i = 0; i < age_range; ++i) {
// 		for (int j = 0; j < passenger_range; ++j) {
// 			car_count += inventory[i][j].size();
// 		}
// 	}
// 	return car_count;
// }

// 해당 판매 번호에 대한 재고를 복원(반환)한다.
// (가장 최근이 아니고 과거의 일정 확률로 생성한 판매 번호에 대한 재고를 복원할 수 있다.)
// 환불 한번 하면 이전 판매기록은 지워도 된다. 환불 조건이 걸리면 main에서 판매 기록을 지워버린다.
void refund(int order_number)
{
	// for (const auto& car : order_car_list[order_number]) {
	// 	inventory[car.age][car.passenger - 2].push_back(car);
	// }
	// cout << "refund and car count: " << emptyTest() << endl;

	int target_order_index = order_number % 100;
	for (int i = 0; i < order_car_list_size[target_order_index]; ++i) {
		CAR& car = order_car_list[target_order_index][i];
		inventory[car.age][car.passenger - 2][inventorySize[car.age][car.passenger - 2]++] = car;
	}

}

// 남아 있는 차의 수를 반환한다.
int empty(void)
{
	order_number = 0;
	int car_count = 0;
	// for (int i = 0; i < age_range; ++i) {
	// 	for (int j = 0; j < passenger_range; ++j) {
	// 		car_count += inventory[i][j].size();
	// 		inventory[i][j].clear(); // Clear the inventory for each age and passenger combination
	// 	}
	// }
	// cout << "vector_max_size_test: " << vector_max_size_test << endl;
	// cout << "max_order_car_size: " << max_order_car_size << endl;
	// cout << "final result: " << car_count << endl;

	for (int i = 0; i < age_range; ++i) {
		for (int j = 0; j < passenger_range; ++j) {
			car_count += inventorySize[i][j];
			inventorySize[i][j] = 0; // Reset the inventory size for each age and passenger combination
		}
	}
	return car_count;
}
