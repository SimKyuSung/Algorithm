/// 13458시험 감독

#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);

	int n, b, c;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;

	size_t ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		ans++;
		if (a[i] > 0)
			ans += (a[i] / c) + bool(a[i] % c);
	}
	cout << ans;
}