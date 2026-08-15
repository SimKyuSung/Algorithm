/// 14731謎紛芥索紀 (Large)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t mod = 1000000007;

long long modular_exponentiation(long long, long long, long long);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long c, k, ans = 0;

	cin >> n;	
	while (n--) {
		cin >> c >> k;
		if (k != 0) {
			// ans += (c * k) % mod * (pow(2, k - 1) % mod);
			ans += (c * k) % mod * modular_exponentiation(2, k - 1, mod);
			ans %= mod;
		}
	}
	cout << ans << "\n";
}

long long modular_exponentiation(long long x, long long exp, long long mod) {
	long long result = 1;
	x %= mod;
	while (exp) {
		// exp를 2진수로 변환
		if (exp % 2)
			result = (result * x) % mod;
		x = (x * x) % mod;
		exp >>= 1;
	}
	return result;
}

/*

최악의 pow 함수

(2 ^ 1000000000) % mod = 무엇?

1
2
4
8
16
32
...




*/