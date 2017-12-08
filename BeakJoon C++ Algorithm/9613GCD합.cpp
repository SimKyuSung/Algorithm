/// 9613GCDÇÕ

#include <iostream>

using namespace std;

int gcd(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, a[100];
	size_t ans;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ans += gcd(a[i], a[j]);
		if (n == 1) ans = a[0];
		cout << ans << "\n";
	}
}

int gcd(int a, int b) {
	int mod = a % b;
	while (mod) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}