/// 5656. [모의 SW 역량테스트] 벽돌 깨기

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;
/*
1. 0 < N < 5;
2. 1 < W < 13;
3. 1 < H < 16 
*/

/*
완탐
12 ^ 4 = 20736
*/

struct Point {
	int y, x;
};

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int w, h;
int game[16][13];
int restore[5][16][13];

inline int MAX(int, int);
int solve(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, ans = 0, counter = 0;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> game[i][j];
				if (game[i][j] > 0)
					counter++;
			}
		}

		for (int j = 0; j < w; j++) {
			memcpy(restore[n], game, sizeof(game));
			ans = MAX(ans, solve(n, j));
		}
		cout << '#' << t << ' ' << counter - ans << endl;
	}
}

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

int solve(int n, int t) {
	//cout << n << ' ' << t << endl;
	if (n == 0)
		return 0;
	// remove (restore[n])
	int y = 0, x = t, ans = 0;
	while (y < h && restore[n][y][x] == 0)
		y++;
	if (y == h)
		return ans;

	queue<Point> q;
	q.push({ y, x });
	//restore[n][y][x] = 0;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		y = now.y;
		x = now.x;
		if (restore[n][y][x] != 0)
			ans++;
		//cout << "remove:  " << y << ' ' << x << endl;
		int counter = restore[n][y][x];
		restore[n][y][x] = 0;
		for (int d = 0; d < 4; d++) {
			int ny = y, nx = x;
			for (int i = 1; i < counter; i++) {
				ny += dy[d];
				nx += dx[d];
				if (ny < 0|| h <= ny || nx < 0 || w <= nx)
					break;
				if (restore[n][ny][nx] != 0) {
					q.push({ ny, nx });
				}
			}
		}
	}

	// drop box
	for (int j = 0; j < w; j++) {
		queue <int> tmp;
		for (int i = h - 1; i >= 0; i--) {
			if (restore[n][i][j] != 0)
				tmp.push(restore[n][i][j]);
			restore[n][i][j] = 0;
		}
		y = h - 1;
		while (!tmp.empty()) {
			restore[n][y][j] = tmp.front();
			tmp.pop();
			y--;
		}
	}

	//int tty;
	//cin >> tty;
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++)
	//		cout << restore[n][i][j] << ' ';
	//	cout << endl;
	//}


	int tmp = 0;
	for (int j = 0; j < w; j++) {
		memcpy(restore[n - 1], restore[n], sizeof(restore[n]));
		tmp = MAX(tmp, solve(n - 1, j));
	}
	return tmp + ans;
}