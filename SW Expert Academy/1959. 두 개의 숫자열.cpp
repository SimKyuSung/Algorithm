/// 1959. 두 개의 숫자열

#include <iostream>
#include <algorithm>

using namespace std;

int a[20];
int b[20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		
		if (m < n) {
			swap(a, b);
			swap(n, m);
		}

		int ans = 0x80000000;
		for (int i = 0; i < m - n + 1; i++) {
			int tmp = 0;
			for (int j = 0; j < n; j++)
				tmp += a[j] * b[j + i];
			ans = max(ans, tmp);
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}