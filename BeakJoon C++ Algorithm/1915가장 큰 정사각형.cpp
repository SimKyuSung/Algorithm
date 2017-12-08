/// 1915가장 큰 정사각형

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <vector <bool> > arr;
vector <vector <int> > dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	arr.resize(n, vector<bool>(m, false));
	dp.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++)
			arr[i][j] = line[j] - '0';
	}
	int ans = dp[0][0] = arr[0][0];
	for (int i = 0; i < m; i++)
		if (arr[0][i]) ans = dp[0][i] = 1;
	for (int i = 0; i < n; i++)
		if (arr[i][0]) ans = dp[i][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j]) dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans * ans;
}