/// 2383. [모의 SW 역량테스트] 점심 식사시간

#include <iostream>
#include <algorithm>
#include <cmath>

#define endl '\n'

using namespace std;

struct Point {
	int y, x;
};

Point p[10];
Point stair[2];
int stairLen[2];

int pc;
int pts[2][10];
bool check[10];

int stairTime(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, ans = 100, input, sc = 0;
		pc = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> input;
				if (input == 1)
					p[pc++] = { i, j };
				else if (input > 1) {
					stairLen[sc] = input;
					stair[sc++] = { i, j };
				}
			}
		}

		for (int i = 0; i < pc; i++) {
			pts[0][i] = abs(stair[0].y - p[i].y) + abs(stair[0].x - p[i].x);
			pts[1][i] = abs(stair[1].y - p[i].y) + abs(stair[1].x - p[i].x);
		}

		for (int i = 0; i < (1 << pc); i++) {
			int tmp = i, counter = 0;
			for (int j = 0; j < pc; j++) {
				check[j] = tmp % 2;
				counter += tmp % 2;
				tmp >>= 1;
			}
			ans = min(ans, max(stairTime(0, pc - counter), stairTime(1, counter)));

		}


		cout << '#' << t << ' ' << ans << endl;
	}
}

int stairTime(int type, int counter) {
	int t = 0, left = 0, right = 0;
	int stairCounter[3] = { 0, 0, 0 };
	int line = 0;

	while (counter) {
		t++;
		for (int i = 0; i < 3; i++) {
			stairCounter[i]--;
			if (stairCounter[i] == 0)
				counter--;
			if (stairCounter[i] < 1 && line) {
				line--;
				stairCounter[i] = stairLen[type];
			}
		}

		for (int i = 0; i < pc; i++) {
			if ((check[i] == type) && (t == pts[type][i]))
				line++;
		}
	}

	return t;
}

/*
0	1	2	3	4	5	6	7	8	9	10	11
	x		x	x		x		xx
	    
		x	x
				x	x
					x	x
							x	x
								x	x
								x	x
		x	x	x	x	x	x	x
								

20 + 10 + 10 + 10 + 10

*/