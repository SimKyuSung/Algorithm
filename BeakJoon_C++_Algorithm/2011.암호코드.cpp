/// 2011.암호코드

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const int MOD = 1000000;
int dp[5001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string encode;
	int n;

	cin >> encode;
	n = encode.size();
	for (int i = 0; i < n; i++)
		encode[i] -= '0';

	if (encode[0] != 0)
		dp[0] = 1;
	for (int i = 0; i < n - 1; i++) {
		int num = encode[i] * 10 + encode[i + 1];
		if (num / 10 != 0)
			dp[i + 1] = (dp[i] + dp[i + 1]) % MOD;
		if (9 < num && num <= 26)
			dp[i + 2] = (dp[i] + dp[i + 2]) % MOD;
	}
	if (encode[n - 1] != 0)
		dp[n] = (dp[n - 1] + dp[n]) % MOD;
	cout << dp[n] << endl;
}

/*

25114
01100
 1200
  222
   242
    46
		11111
	1111A			111B
	111A	11B		11A		1B
	11A	 1B	1A	0B	1A 0B	0A
	1A0B 0A	0A		0A
	0A
aaaaa
aaab
aaba
abaa
abb

baaa
bab
bba

1111A
111B


10000



*/