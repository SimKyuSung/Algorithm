/// 2068. 최대수 구하기

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, ans = 0;
		for (int i = 0; i < 10; i++) {
			cin >> n;
			ans = max(ans, n);
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}