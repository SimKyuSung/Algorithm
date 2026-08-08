/// 2117. [모의 SW 역량테스트] 홈 방범 서비스

#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'
#define MAX(a, b) a > b ? a : b

using namespace std;

struct Point {
	int y, x;
};
vector <Point> home;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, ans = 1, counter = 0, input, k = 1;
		home.clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> input;
				if (input) {
					home.push_back({ i, j });
					counter++;
				}
			}
		}


		while (k * k + (k - 1) * (k - 1) <= counter * m)
			k++;
		int cost, profit;
		while (k--) {
			cost = k * k + (k - 1) * (k - 1);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int tmpAns = 0;
					profit = 0;
					for (int h = 0; h < counter; h++) {
						if (abs(i - home[h].y) + abs(j - home[h].x) < k) {
							profit += m;
							tmpAns++;
						}
					}
					if (profit >= cost)
						ans = MAX(ans, tmpAns);
				}
			}
		}


		cout << '#' << t << ' ' << ans << endl;
	}
}

/*

2k ^ 2 - 2k + 1

0
4
8
12
16

*/