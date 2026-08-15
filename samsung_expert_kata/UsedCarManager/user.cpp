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

void buy(CAR car)
{

}

void filter_by_age(int from, int to)
{

}

void filter_by_passenger(int from, int to)
{

}

void filter_by_engine(int from, int to)
{

}

void filter_by_price(int from, int to)
{

}

int sell(void)
{
	return 0;
}

void refund(int order_number)
{

}

int empty(void)
{

	return 0;
}
