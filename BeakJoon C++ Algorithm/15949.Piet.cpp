/// 15949.Piet

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
char piet[100][100];
bool check[100][100];

void dfs(int, int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> piet[i][j];
	dfs(0, 0, 0, 0);
	cout << endl;
}

void dfs(int y, int x, int dp, int cp) {
	cout << piet[y][x];
	memset(check, 0, sizeof(check));
	int nextY[4][2] = { n, 0, 0, 0, 0, n, n, n };
	int nextX[4][2] = { 0, 0, 0, m, m, m, m, 0 };

	queue <int> q;
	q.push(y * 100 + x);
	check[y][x] = 1;

	while (!q.empty()) {
		y = q.front() / 100;
		x = q.front() % 100;
		q.pop();


		if (nextX[0][0] <= x) {
			if (nextX[0][0] == x) {
				nextY[0][0] = min(nextY[0][0], y);
				nextY[0][1] = max(nextY[0][1], y);
			}
			else
				nextY[0][0] = nextY[0][1] = y;
			nextX[0][0] = nextX[0][1] = x;
		}
		if (nextY[1][0] <= y) {
			if (nextY[1][0] == y) {
				nextX[1][0] = max(nextX[1][0], x);
				nextX[1][1] = min(nextX[1][1], x);
			}
			else
				nextX[1][0] = nextX[1][1] = x;
			nextY[1][0] = nextY[1][1] = y;
		}
		if (nextX[2][0] >= x) {
			if (nextX[2][0] == x) {
				nextY[2][0] = max(nextY[2][0], y);
				nextY[2][1] = min(nextY[2][1], y);
			}
			else
				nextY[2][0] = nextY[2][1] = y;
			nextX[2][0] = nextX[2][1] = x;
		}
		if (nextY[3][0] >= y) {
			if (nextY[3][0] == y) {
				nextX[3][0] = min(nextX[3][0], x);
				nextX[3][1] = max(nextX[3][1], x);
			}
			else
				nextX[3][0] = nextX[3][1] = x;
			nextY[3][0] = nextY[3][1] = y;
		}

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !check[ny][nx] && piet[ny][nx] == piet[y][x]) {
				check[ny][nx] = 1;
				q.push(ny * 100 + nx);
			}
		}
	}
	//for (int i = 0; i < 4; i++) {
	//	cout << nextY[i][0] << ' ' << nextX[i][0] << endl;
	//	cout << nextY[i][1] << ' ' << nextX[i][1] << endl;
	//}
	//cout << endl << endl;

	for (int d = 0; d < 4; d++) {
		int ny, nx;
		ny = nextY[dp][cp] + dy[dp];
		nx = nextX[dp][cp] + dx[dp];
		if (0 <= ny && ny < n && 0 <= nx && nx < m && piet[ny][nx] != 'X') {
			dfs(ny, nx, dp, cp);
			return;
		}
		cp = !cp;
		ny = nextY[dp][cp] + dy[dp];
		nx = nextX[dp][cp] + dx[dp];
		if (0 <= ny && ny < n && 0 <= nx && nx < m && piet[ny][nx] != 'X') {
			dfs(ny, nx, dp, cp);
			return;
		}
		dp = (dp + 1) % 4;
	}
	return;
}

/*

	3
2		0
	1

	-1
	1
*/