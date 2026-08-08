/// 3431. 준환이의 운동관리

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int l, u ,x, ans = 0;
		cin >> l >> u >> x;

		if (x < l)
			ans = l - x;
		if (x > u)
			ans = -1;
		cout << '#' << t << ' ' << ans << '\n';
	}
}