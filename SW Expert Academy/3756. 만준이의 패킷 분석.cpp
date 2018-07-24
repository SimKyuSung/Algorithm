/// 3756. 만준이의 패킷 분석

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int dp[1000000];

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		string s;
		memset(dp, 0, sizeof(dp));

		cin >> n >> s;

		for (int i = 1; i < n; i++) {
			int j = dp[i - 1];
			while (s[i] != s[j] && j != 0)
				j = dp[j - 1];
			if (s[i] == s[j])
				dp[i] = j + 1;
		}

		cout << '#' << t << ' ' << n - dp[n - 1] << '\n';

	}
}