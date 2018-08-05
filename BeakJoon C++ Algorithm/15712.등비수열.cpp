/// 15712.등비수열

#include <iostream>

#define endl '\n'

using namespace std;

size_t powermod(size_t, size_t, size_t);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	size_t a, r, n, mod, ans = 0;
	cin >> a >> r >> n >> mod;

	// sigma
	if (r != 1)
		ans = (a * (powermod(r, n, mod) - 1)) / (r - 1);
	else
		ans = n * a;
	cout << ans % mod << endl;
}

size_t powermod(size_t base, size_t exp, size_t mod) {
	size_t ans = 1, x = base % mod;
	while (exp) {
		// 1승수 있으면 곱해서 제거
		if (exp % 2)
			ans = (ans * x) % mod;
		// 2	4	16	256
		x = (x * x) % mod;
		exp >>= 1;
	}
	return ans;
}

/*

f(x) % mod = a * (r^n - 1) / (r - 1) % mod

*/