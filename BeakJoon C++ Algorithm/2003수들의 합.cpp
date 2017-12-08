/// 2003수들의 합

#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, total = 0, left = 0;
	cin >> n >> m;

	a.resize(n + 1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total += a[i];
		while (total > m) total -= a[left++];
		if (total == m) ans++;
	}
	cout << ans;
}