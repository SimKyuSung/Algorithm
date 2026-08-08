/// 12094_2048(Hard)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

const int maxLv = 10;
int n, a;

//			  u  r   d  l
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int dsx[4] = { 0, 1, 1, 0 };
int dsy[4] = { 0, 0, 1, 1 };

unsigned char tile[11][20][20];
int counter[20];

unsigned char dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			unsigned char tmp = 0;
			while (a) {
				a >>= 1;
				tmp++;
			}
			tile[0][i][j] = tmp;
		}
	}
	cout << (1 << (dfs(0) - 1)) << '\n';
}

// dfs
unsigned char dfs(int lv) {
	// 0. 테스트 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (int)tile[lv][i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	unsigned char ans = 0;
	// 1. 종료조건
	if (lv == maxLv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				ans = max(ans, tile[lv][i][j]);
		}
		return ans;
	}

	for (int d = 0; d < 4; d++) {
		memset(counter, 0, sizeof(counter));
		int xs = dsx[d] * (n - 1);
		int ys = dsy[d] * (n - 1);
		for (int i = 0; i < n; i++) {
			int x = xs, y = ys;
			int index = x, indey = y;
			int num = 0;
			for (int j = 0; j < n; j++) {
				tile[lv + 1][y][x] = 0;
				if (tile[lv][y][x]) {
					if (tile[lv][y][x] == num) {
						index -= dx[d];
						indey -= dy[d];
						tile[lv + 1][indey][index]++;
						num = 0;
					}
					else {
						num = tile[lv][y][x];
						tile[lv + 1][indey][index] = num;
					}
					counter[tile[lv + 1][indey][index]]++;
					index += dx[d];
					indey += dy[d];
				}
				x += dx[d];
				y += dy[d];
			}
			xs += dx[(d + 3) % 4];
			ys += dy[(d + 3) % 4];
		}

		if (memcmp(tile[lv], tile[lv + 1], sizeof(tile[lv])) == 0 || (lv > 0 && memcmp(tile[lv - 1], tile[lv + 1], sizeof(tile[lv])) == 0))
			continue;

		for (int c = 19; c > 0; c--)
			counter[c] += counter[c + 1] * 2;
		if (ans == 0 || counter[ans + lv - maxLv + 1] >= (1 << (maxLv - lv)))
			ans = max(ans, dfs(lv + 1));
	}
	return ans;
}