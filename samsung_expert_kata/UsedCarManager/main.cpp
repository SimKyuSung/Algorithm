#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int MAX_CAR = 1000000;
static int seed = 3;

struct CAR
{
	int age;       // 0 ~ 19
	int passenger; // 2 ~ 12
	int engine;    // 1000 ~ 4999
	int price;     // 10000 ~ 39999
};

extern void buy(CAR car);
extern void filter_by_age(int from, int to);
extern void filter_by_passenger(int from, int to);
extern void filter_by_engine(int from, int to);
extern void filter_by_price(int from, int to);

extern int sell(void);
extern void refund(int order_number);
extern int empty(void);

static int pseudo_rand(void) {
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

static void build(CAR* car)
{
	car->age = pseudo_rand() % 20;
	car->passenger = 2 + (pseudo_rand() % 11);
	car->engine = 1000 + (pseudo_rand() % 4000);
	car->price = 10000 + (pseudo_rand() % 30000);
}

int main(void)
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);
	seed = 3;

	int PERFORMANCE = 0;
	int ans;
	int order_number = -1;

	for (register int TRY = 1; TRY <= 10; TRY++)
	{
		time_t start = clock();

		for (register int c = 0; c < MAX_CAR; c++)
		{
			CAR car;

			build(&car);
			buy(car);

			if ((pseudo_rand() % 100) == 0)
			{
				filter_by_age(pseudo_rand() % 20, pseudo_rand() % 20);
				filter_by_passenger(2 + (pseudo_rand() % 11), 2 + (pseudo_rand() % 11));
				filter_by_engine(1000 + (pseudo_rand() % 4000), 1000 + (pseudo_rand() % 4000));
				filter_by_price(10000 + (pseudo_rand() % 30000), 10000 + (pseudo_rand() % 30000));
				int ret = sell();
				if ((pseudo_rand() % 10) == 0) order_number = ret;
			}

			if ((pseudo_rand() % 10000) == 0)
			{
				if (order_number != -1)
				{
					refund(order_number);
					order_number = -1;
				}
			}
		}

		int RESULT = empty();
		order_number = -1;
		PERFORMANCE += ((clock() - start) / (CLOCKS_PER_SEC / 1000));

		scanf("%d", &ans);
		if (RESULT != ans){
			PERFORMANCE += 1000000;
		}
	}
	if (PERFORMANCE <= 6000)
		printf("PASS\n");
	else
		printf("PERFORMANCE = %d\n", PERFORMANCE);

	return 0;
}
