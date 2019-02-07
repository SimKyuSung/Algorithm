/// 1743.음식물 피하기

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool trash[104][104];

int dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	while (k--) {
		int r, c;
		cin >> r >> c;
		trash[r][c] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (trash[i][j])
				ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;

}

int dfs(int y, int x) {
	int ret = 1;
	trash[y][x] = 0;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (trash[ny][nx])
			ret += dfs(ny, nx);
	}
	return ret;
}