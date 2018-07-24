/// 4299. 태혁이의 사랑은 타이밍

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int d, h, m, ans = 0;
		cin >> d >> h >> m;
		ans = m - 11 + (h - 11) * 60 + (d - 11) * 24 * 60;
		if (ans < 0)
			ans = -1;
		cout << '#' << t << ' ' << ans << endl;
	}
}