/// 2225.ÇÕºÐÇØ

#include <iostream>

#define endl '\n'

using namespace std;

const int MOD = 1000000000;
const int MAX = 201;
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < MAX; i++)
		dp[0][i] = 1;
	for (int i = 1; i < MAX; i++) {
		dp[i][1] = 1;
		for (int j = 2; j < MAX; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	int n, k;
	cin >> n >> k;
	cout << dp[n][k] << endl;
}

/*
	1	2	3	4	5	6	7	8	9	10
1	1	2	3	4	5	6	7	8
2	1	3	6	
3	1	4	
4	1
5	1
6	1
7	1
8	1
9	1
10	1
11	1
12	1
13	1
14	1


*/