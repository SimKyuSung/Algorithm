/// 3282. 0/1 Knapsack

#include <iostream>
#include <algorithm>
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
		int n, k, v, c, ans = 0;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;

		cin >> n >> k;
		while (n--) {
			cin >> v >> c;
			for (int i = 1000; i >= v; i--) {
				if (dp[i - v] != -1)
					dp[i] = max(dp[i], dp[i - v] + c);
			}
		}
		for (int i = 0; i <= k; i++)
			ans = max(ans, dp[i]);
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*
	v	c		dp
	4	5		dp[4] = 5
	1	2		dp[1] = 2, dp[5] = 7
	3	2		
*/