/// 2583영역 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool rec[101][101];

vector <int> ans;
int dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	int x1, y1, x2, y2;
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				rec[i][j] = true;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!rec[i][j])
				ans.push_back(dfs(j, i));

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int res : ans)
		cout << res << " ";

}
int dfs(int x, int y) {
	int ret = 1;
	rec[y][x] = true;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (0 <= nx && nx < m && 0 <= ny && ny < n && !rec[ny][nx])
			ret += dfs(nx, ny);
	}
	return ret;
}