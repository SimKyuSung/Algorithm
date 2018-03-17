/// 1305±¤°í

#include <iostream>
#include <string>

using namespace std;

int dp[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;

	cin >> n >> s;

	for (int i = 1; i < n; i++) {
		int j = dp[i - 1];
		while (s[i] != s[j] && j != 0)
			j = dp[j - 1];
		if (s[i] == s[j])
			dp[i] = j + 1;
	}

	cout << n - dp[n - 1];
}

/*
aabaaa
010122

abaaab
001112

baaaba
000012

aaabaa
012012

aaaaa
01234

*/