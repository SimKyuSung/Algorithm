/// 13416주식 투자

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		// n <= 1000
		int ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y = 0;
			for (int j = 0; j < 3; j++) {
				cin >> x;
				y = max(y, x);
			}
			ans += y;
		}
		cout << ans << '\n';
	}
}