/// 1958.LCS 3

#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int dp[101][101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b, c;
	cin >> a >> b >> c;
	int na = a.size(), nb = b.size(), nc = c.size();

	for (int i = 0; i < na; i++) {
		for (int j = 0; j < nb; j++) {
			for (int k = 0; k < nc; k++) {
				int &x = dp[i + 1][j + 1][k + 1];
				if (a[i] == b[j] && b[j] == c[k])
					x = 1 + dp[i][j][k];
				else x = max(dp[i][j + 1][k + 1], max(dp[i + 1][j][k + 1], dp[i + 1][j + 1][k]));
				//cout << dp[i][j][k];
			}
			//cout << ' ';
		}
		//cout << endl;
	}

	cout << dp[na][nb][nc] << endl;
}