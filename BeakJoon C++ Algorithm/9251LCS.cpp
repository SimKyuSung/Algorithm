/// 9251LCS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <int> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	dp.resize(b.length(), 0);

	int ans = 0;
	for (int i = 0; i < a.length(); i++) {
		int tmpAns = 0;
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				int tmp = tmpAns;
				tmpAns = max(tmpAns, dp[j]);
				dp[j] = max(tmp + 1, dp[j]);
			}
			else {
				tmpAns = max(tmpAns, dp[j]);
			}
			ans = max(dp[j], ans);
			cout << dp[j];
		}
		cout << endl;
	}
	cout << ans << endl;
}