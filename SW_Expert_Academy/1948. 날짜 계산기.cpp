/// 1948. 날짜 계산기

#include <iostream>

using namespace std;

int lastDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int m1, d1, m2, d2, day = 0;
		cin >> m1 >> d1 >> m2 >> d2;
		for (int i = 0; i < m2 - 1; i++)
			day += lastDay[i];
		for (int i = 0; i < m1 - 1; i++)
			day -= lastDay[i];
		day += d2 - d1;

		cout << '#' << t << ' ' << day + 1 << '\n';
	}
}