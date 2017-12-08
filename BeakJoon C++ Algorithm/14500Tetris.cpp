/// 14500Tetris

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int n, m;
int w[500][500];
int s[500][500];

//			down, right, up, left
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 1. 4블럭 재귀
int tetris(int, int, int);

// 3. T자 블럭 8종
int t();



int main()
{
	memset(w, 0, sizeof(w));
	memset(s, -1, sizeof(s));
	cin >> n >> m;
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	cin >> w[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = max(ans, tetris(i, j, 0));
	ans = max(ans, t());
	cout << ans << endl;
}

int tetris(int y, int x, int t) {
	int ret = w[y][x];
	s[y][x] = 1;
	int maximum = 0;
	for (int i = 0; i < 4; i++) {
		// 배열 범위 에러
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > -1 && tx < m && ty > -1 && ty < n && s[ty][tx] != 1 && t < 3)
			maximum = max(maximum, tetris(ty, tx, t + 1));
	}
	s[y][x] = -1;
	ret += maximum;
	return ret;
}

int t() {
	int ret = 0;

	// 가로 긴값
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 2; j++)
			ret = max(ret, w[i][j] + w[i][j + 1] + w[i][j + 2] + w[i + 1][j + 1]);

	// 가로 긴값
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m - 2; j++)
			ret = max(ret, w[i][j] + w[i][j + 1] + w[i][j + 2] + w[i - 1][j + 1]);

	// 세로 긴값
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 1; j++)
			ret = max(ret, w[i][j] + w[i + 1][j] + w[i + 2][j] + w[i + 1][j + 1]);

	// 세로 긴값
	for (int i = 0; i < n - 2; i++)
		for (int j = 1; j < m; j++)
			ret = max(ret, w[i][j] + w[i + 1][j] + w[i + 2][j] + w[i + 1][j - 1]);

	return ret;
}
