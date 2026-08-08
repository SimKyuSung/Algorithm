/// 4991.·Îº¿ Ã»¼Ò±â

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int w, h;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int dis[11][11];
int tmp[20][20];
char room[20][20];

struct Point {
	int y, x;
};

int n, counter[11];
Point p[11];

bool init();
bool bfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		cin >> w >> h;
		if (w == 0)
			return 0;

		n = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char &r = room[i][j];
				cin >> r;
				if (r == 'o') {
					p[0] = { i, j };
					r = 0;
				}
				else if (r == '*') {
					p[n] = { i, j };
					r = n++;
				}
			}
		}
		if (init()) {
			cout << -1 << endl;
			continue;
		}

		int ans = 4000000;
		do {
			int tmp = 0;
			for (int i = 1; i < n; i++)
				tmp += dis[counter[i - 1]][counter[i]];
			ans = min(ans, tmp);
		} while (next_permutation(counter + 1, counter + n));
		cout << ans << endl;
	}
}

bool init() {
	for (int i = 0; i < n; i++) {
		if (bfs(i)) 
			return 1;
		counter[i] = i;
	}
	return 0;
}

bool bfs(int t) {

	memset(tmp, -1, sizeof(tmp));
	queue <Point> q;
	q.push(p[t]);
	tmp[p[t].y][p[t].x] = 0;

	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (0 <= ny && ny < h && 0 <= nx && nx < w && room[ny][nx] != 'x' && tmp[ny][nx] == -1) {
				tmp[ny][nx] = tmp[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		dis[t][i] = tmp[p[i].y][p[i].x];
		dis[i][t] = dis[t][i];
		if (dis[i][t] == -1)
			return 1;
	}
	return 0;
}