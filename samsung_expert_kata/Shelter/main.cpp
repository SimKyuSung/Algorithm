#include <stdio.h>
#include <stdlib.h>

int seed = 0;
const int FLOOR = 10000;
extern void assign(int house[FLOOR][10000]);

int main(void)
{
	static int house[FLOOR][10000];
	static int org[FLOOR][10000];
	static int shelter[FLOOR][3];

	scanf("%d", &seed);
	srand(seed);

	for (register int f = 0; f < FLOOR; f++)
	{
		for (register int c = 0; c < 10000; c++)
			org[f][c] = house[f][c] = 1 + (rand() % 9);

		for (register int c = 0; c < 3;)
		{
			int r = rand() % 10000;
			if (house[f][r] == 0) continue;

			org[f][r] = house[f][r] = 0;
			shelter[f][c++] = r;
		}
	}

	double TOTAL = 0.0;

	assign(house);

	for (register int f = 0; f < FLOOR; f++)
	{
		int sum[3] = { 0, 0, 0 };

		for (register int i, c = 0; c < 10000; c++)
		{
			if (org[f][c] == 0) continue;

			for (i = 0; i < 3; i++)
				if (house[f][c] == shelter[f][i])
				{
					sum[i] += org[f][c];

					if (sum[i] <= 20000) TOTAL += abs(shelter[f][i] - c);
					else {
						TOTAL += 10000;
						printf("FAIL: OVERFLOW: %d\n", i);
					}
					break;
				}

			if (i == 3) {
				TOTAL += 10000;
				printf("FAIL: UNASSIGNED\n");
			}
		}
		// printf("total house: %d\n", sum[0] + sum[1] + sum[2]);
	}
	double SCORE = TOTAL / 10000 / FLOOR;
	if (SCORE < 1640){
		printf("PASS: %.10lf\n", SCORE);
	}
	else{
		printf("FAIL\n");
		printf("SCORE = %.10lf\n", TOTAL / 10000 / FLOOR);
	}
	return 0;
}
