/// 13699Á¡È­½Ä

#include <iostream>
#include <string>

using namespace std;

size_t dp[36];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];
	}
	cout << dp[n] << endl;
}