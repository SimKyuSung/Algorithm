/// 2591.숫자카드

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

size_t dp[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string encode;
	cin >> encode;
	int n = encode.size();
	for (int i = 0; i < n; i++)
		encode[i] -= '0';
	encode += 99;

	dp[0] = 1;
	for (int i = 0; i < n - 1; i++) {
		int num = encode[i] * 10 + encode[i + 1];
		if (num / 10 != 0)
			dp[i + 1] = dp[i] + dp[i + 1];
		if (9 < num && num <= 34)
			dp[i + 2] = dp[i] + dp[i + 2];
	}
	if (encode[n - 1] != 0)
		dp[n] += dp[n - 1];
	cout << dp[n] << endl;
}

/*

27123
111
1120
11222
112242

112246

*/