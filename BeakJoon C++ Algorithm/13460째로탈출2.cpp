/// 13460째로탈출2

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

char maze[10][10];
bool dp[10][10][10][10];

// 남, 북, 서, 동
const short dx[4] = { 0, 0, -1, 1 };
const short dy[4] = { 1, -1, 0, 0 };

struct coor {
	short rY, rX, bY, bX, d;
};

queue <coor> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	coor init;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'R') {
				init.rY = i;
				init.rX = j;
				maze[i][j] = '.';
			}
			else if (maze[i][j] == 'B') {
				init.bY = i;
				init.bX = j;
				maze[i][j] = '.';
			}
		}
	}

	init.d = -1;
	dp[init.rY][init.rX][init.bY][init.bX] = 1;
	q.push(init);

	int ans = 0;
	while (!q.empty()) {
		int qSize = q.size();
		ans++;

		if (ans > 10) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < qSize; i++) {
			coor now = q.front();
			q.pop();
			for (short d = 0; d < 4; d++) {
				if (now.d == d) continue;

				short ry = now.rY, rx = now.rX, by = now.bY, bx = now.bX;
				int bCounter = 0, rCounter = 0;

				// 1. 파란공 움직이기
				while (maze[by][bx] == '.') {
					by += dy[d];
					bx += dx[d];
					bCounter++;
				}
				if (maze[by][bx] == 'O')
					continue;
				by -= dy[d];
				bx -= dx[d];

				// 2. 빨간공 움직이기
				while (maze[ry][rx] == '.') {
					ry += dy[d];
					rx += dx[d];
					rCounter++;
				}
				if (maze[ry][rx] == 'O') {
					cout << ans << endl;
					return 0;
				}
				ry -= dy[d];
				rx -= dx[d];

				// 3. 같은 위치에 있다면 많이 움직인 친구를 뒤로 보냄
				if (ry == by && rx == bx) {
					if (bCounter > rCounter) {
						by -= dy[d];
						bx -= dx[d];
					}
					else {
						ry -= dy[d];
						rx -= dx[d];
					}
				}
				if (!dp[ry][rx][by][bx]) {
					dp[ry][rx][by][bx] = 1;
					q.push({ ry, rx, by, bx, d });
				}
			}
		}
	}
	cout << -1 << endl;
}