/// 1860. 진기의 최고급 붕어빵

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, k;
		string ans = "Possible";
		cin >> n >> m >> k;
		a.resize(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());

		int sum = 0, pc = 0;
		if (a.front() == 0)
			ans = "Impossible";
		for (int i = 1; i <= a.back(); i++) {
			if (i % m == 0)
				sum += k;
			if (i == a[pc]) {
				sum--;
				if (sum < 0) {
					ans = "Impossible";
					break;
				}
				pc++;
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}