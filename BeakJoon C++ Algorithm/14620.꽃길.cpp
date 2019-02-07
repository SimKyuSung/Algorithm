/// 14620.²É±æ

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int n;
int initialPrice[104][104];
int flag[104][104];

int dx[] = { 2,1,2,3,0,1,2,3,4,1,2,3,2 };
int dy[] = { 0,1,1,1,2,2,2,2,2,3,3,3,4 };
int rt[] = { 2,5,6,7,10 };

int dfs(int level) {
	if (level == 3)
		return 0;
	int ret = 5000;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= n - 1; j++) {
			if (flag[i][j] == 0) {
				for (int d = 0; d < 13; d++) {
					int nx = j + dx[d];
					int ny = i + dy[d];
					flag[ny][nx]++;
				}
				int ans = 0;
				for (int d = 0; d < 5; d++) {
					int nx = j + dx[rt[d]];
					int ny = i + dy[rt[d]];
					ans += initialPrice[ny][nx];
				}
				ret = min(ret, ans + dfs(level + 1));
				for (int d = 0; d < 13; d++) {
					int nx = j + dx[d];
					int ny = i + dy[d];
					flag[ny][nx]--;
				}
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int d = 0; d < 13; d++) {
		dx[d] -= 2;
		dy[d] -= 2;
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> initialPrice[i][j];
	}
	cout << dfs(0) << endl;
}