/// 10803.정사각형 만들기

#include <iostream>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int dp[10001][101];

int function(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;
	for (int i = 1; i < 101; i++) {
		dp[i][i] = 1;
		
		dp[i][0] = 0;
		dp[0][i] = 0;
		dp[i][1] = i;
		dp[1][i] = i;

		dp[i][2] = i / 2;
		dp[2][i] = i / 2;
		if (i % 2 == 1) {
			dp[i][2] += 2;
			dp[2][i] += 2;
		}


	}
	for (int i = 101; i < 10001; i++) {
		dp[i][0] = 0;
		dp[i][1] = i;
		if (i % 2 == 0)
			dp[i][2] = i / 2;
		else
			dp[i][2] = i / 2 + 2;
	}

	int n, m;
	cin >> n >> m;
	if (m > n)
		swap(n, m);
	cout << function(n, m) << endl;
}

int function(int n, int m) {
	int ret = dp[n][m];
	if (ret != -1)
		return ret;
	if (n % m == 0)
		return dp[n][m] = n / m;
	ret = 100 * 10000;
	//// 가로로 자르기!
	//for (int i = 1; i <= n / 2; i++) {
	//	ret = min(ret, function(max(i, m), min(i, m)) + function(max(n - i, m), min(n - i, m)));
	//}
	//// 세로로 자르기!
	//for (int j = 1; j <= m / 2; j++) {
	//	ret = min(ret, function(max(n, j), min(n, j)) + function(max(n, m - j), min(n, m - j)));
	//}

	//???

	int nextN = max(n - m, n);
	int nextM = min(n - m, n);
	return dp[n][m] = function;
}

/*
5 * 6

5*5 + 5*1
5*4


*/