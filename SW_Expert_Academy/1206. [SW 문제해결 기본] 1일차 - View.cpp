/// 1206. [S/W 문제해결 기본] 1일차 - View

#include <iostream>
#include <algorithm>

using namespace std;

int apt[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	// cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> apt[i];

		int ans = 0;
		for (int i = 2; i < n - 2; i++) {
			int x = 0x7fffffff;
			x = min(x, apt[i] - apt[i - 2]);
			x = min(x, apt[i] - apt[i - 1]);
			x = min(x, apt[i] - apt[i + 1]);
			x = min(x, apt[i] - apt[i + 2]);
			x = max(x, 0);
			ans += x;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}