/// 2749피보나치 수3
// https://www.acmicpc.net/blog/view/28

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000;
const int period = 15 * mod / 10;
vector <int> f(period);

int main()
{
	unsigned long long n;
	cin >> n;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < period; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
	cout << f[n % period];
}

/*
(a + b) % mod = ((a % mod) + (b % mod)) % mod
18446744073709551615
1000000000000000000
*/