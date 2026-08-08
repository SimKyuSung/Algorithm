/// 16137.°ß¿ì¿Í Á÷³à

#include <iostream>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

struct State {
	int y, x, t;
	bool c, s;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;
int sky[10][10];
int ans[10][10][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sky[i][j];
			ans[i][j][0] = ((unsigned)-1) >> 1;
			ans[i][j][1] = ((unsigned)-1) >> 1;
		}
	}

	queue <State> q;
	q.push({ 0, 0, 0, sky[0][0] != 1, 0 });
	ans[0][0][0] = 0;

	while (!q.empty()) {
		State now = q.front();
		q.pop();
		//cout << now.y << ' ' << now.x << ' ' << now.t << ' ' << now.c << ' ' << now.s <<endl;
		now.t++;
		for (int d = 0; d < 4; d++) {
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && now.t < ans[ny][nx][now.s]) {
				if (sky[ny][nx] == 1) {
					ans[ny][nx][now.s] = now.t;
					q.push({ ny, nx, now.t, 0, now.s });
				}
				else if (!now.c) {
					if (sky[ny][nx] == 0 && !now.s) {
						int t = ((now.t - 1) / m + 1) * m;
						ans[ny][nx][1] = t;
						q.push({ ny, nx, t, 1, 1 });
					}
					else if (sky[ny][nx] != 0) {
						int t = ((now.t - 1) / sky[ny][nx] + 1) * sky[ny][nx];
						ans[ny][nx][now.s] = t;
						q.push({ ny, nx, t, 1, now.s });
					}
				}
			}
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++)
		//		cout << ans[i][j] << ' ';
		//	cout << endl;
		//}
	}
	n--;
	cout << min(ans[n][n][0], ans[n][n][1]) << endl;
}

/*

0	2	4	6	8	10
0 1 2 3 4 5 6 7 8 9 10
	2	4	6	8	10
  2 2 4 4 6 6 8 8 1010
      3     6     9
  3 3 3 6 6 6




*/