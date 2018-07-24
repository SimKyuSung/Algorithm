/// 2007. 패턴 마디의 길이

#include <iostream>
#include <string>

using namespace std;

int dp[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		string s;
		cin >> s;
		n = s.size();
		cout << ' ';
		for (int i = 1; i < n; i++) {
			int j = dp[i - 1];
			while (s[i] != s[j] && j != 0)
				j = dp[j - 1];
			if (s[i] == s[j])
				dp[i] = j + 1;
			cout << dp[i];
		}

		cout << '#' << t << ' ' << n - dp[n - 1] << '\n';

	}
}