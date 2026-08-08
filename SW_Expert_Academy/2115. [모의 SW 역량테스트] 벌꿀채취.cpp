/// 2115. [모의 SW 역량테스트] 벌꿀채취

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, m, c;
int box[10][10];
int dp[10][10];
int dpMAX[10];
int dp_MAX[10];

int getMoney(int, int);
int secondBee(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> box[i][j];
		}

		for (int i = 0; i < n; i++) {
			dpMAX[i] = 0;
			for (int j = 0; j <= n - m; j++) {
				dp[i][j] = getMoney(i, j);
				dpMAX[i] = max(dpMAX[i], dp[i][j]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			dp_MAX[i] = 0;
			for (int j = 0; j < n; j++)
				if (i != j)
					dp_MAX[i] = max(dp_MAX[i], dpMAX[j]);
		}


		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++)
				ans = max(ans, dp[i][j] + secondBee(i, j));
		}
		cout << '#' << t << ' ' << ans << endl;
	}
}

int getMoney(int y, int x) {
	int line[10];
	for (int j = 0; j < m; j++)
		line[j] = box[y][x + j];

	int ret = 0;
	for (int i = 0; i < (1 << m); i++) {
		int tmp = i, counter = 0, tmpRet = 0;
		for (int j = 0; j < m; j++) {
			if (tmp % 2) {
				counter += line[j];
				tmpRet += line[j] * line[j];
			}
			tmp >>= 1;
		}
		if (counter <= c)
			ret = max(ret, tmpRet);
	}
	return ret;
}

int secondBee(int y, int x) {
	int ret = dp_MAX[y];
	for (int j = 0; j <= x - m; j++) {
		ret = max(ret, dp[y][j]);
	}
	for (int j = x + m; j < n - m; j++) {
		ret = max(ret, dp[y][j]);
	}

	return ret;
}

/*

2^10 = 1024
1024 * 100


*/