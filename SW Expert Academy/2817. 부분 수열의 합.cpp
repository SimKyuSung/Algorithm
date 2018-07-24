/// 2817. 부분 수열의 합

#include <iostream>
#include <memory.h>

#define endl '\n'

using namespace std;

int dp[1004];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, k, a;
		memset(dp, 0, sizeof(dp));

		cin >> n >> k;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int index = k; index >= a; index--)
				dp[index] += dp[index - a];
		}

		/*for (int i = 0; i <= k; i++)
			cout << dp[i] << endl;*/


		cout << '#' << t << ' ' << dp[k] << endl;
	}
}


/*

1						0
1	1					1
1	1	1	1			2
1	2	2	2	1		1
1	2	3	4	3	1	2

*/