/// 15624.피보나치 수 7

#include <iostream>

using namespace std;

const int MOD = 1000000007;

int fibo[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	fibo[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		fibo[i] = (fibo[i - 2] + fibo[i - 1]) % MOD;
	cout << fibo[n] << endl;

}