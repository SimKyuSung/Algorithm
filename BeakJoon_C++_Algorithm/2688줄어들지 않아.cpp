/// 2688줄어들지 않아

#include <iostream>

using namespace std;

size_t dp[64][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int j = 0; j < 10; j++)
		dp[0][j] = j + 1;
	for (int i = 1; i < 64; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n - 1][9] << '\n';
	}
}

/*

1		1	1	1	1	...	1
0		1	2	3	4	...	10	
3		1	3	6	10	...	55
4		1	4	10	20
...
64		1	........		...
65		1	


0	55							55
1	55 - 10						45
2	55 - 10 - 9					36
3	55 - 10 - 9 - 8				28
4								21
5								15
6								10
7								6
8								3
9	55 - 10 - 9 - 8 - ... 2		1


*/