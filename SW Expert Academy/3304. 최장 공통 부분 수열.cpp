/// 3304. 최장 공통 부분 수열

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string s1, s2;
		int ans = 0, dp[1004];
		memset(dp, 0, sizeof(dp));

		cin >> s1 >> s2;
		for (int i = 0; i < s1.size(); i++) {
			int tmpAns = 0;
			for (int j = 0; j < s2.size(); j++) {
				int tmp = dp[j];
				if (s1[i] == s2[j])
					dp[j] = max(dp[j], tmpAns + 1);
				tmpAns = max(tmpAns, tmp);
				//cout << dp[j] << ' ';
			}
			//cout << endl;
		}
		for (int i = 0; i < s2.size(); i++)
			ans = max(ans, dp[i]);
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*
	acaykp
c   010000
a   112000
p   112001
c   122001
a   123001
k	123041


	aaaaa
a	11111
a	12222
a	12333

	aaa
a	111
a	122	
a	123
a	123
a

*/