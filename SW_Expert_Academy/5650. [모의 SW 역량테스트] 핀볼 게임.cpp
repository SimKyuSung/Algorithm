/// 5650. [¸ðÀÇ SW ¿ª·®Å×½ºÆ®] ÇÉº¼ °ÔÀÓ

#include <iostream>

#define endl '\n'

using namespace std;

//	 w n e s
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n;
int g[102][102];

struct Point {
	int y, x;
}wh[20];

int solve(int, int, int);
inline int MAX(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int ans = 0;
		// init
		for (int i = 6; i < 20; i++)
			wh[i].y = wh[i].x = -1;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int &k = g[i][j];
				cin >> k;
				if (k > 5) {
					if (wh[k].y == -1) {
						wh[k].y = i;
						wh[k].x = j;
					}
					else {
						wh[k + 5].y = wh[k].y;
						wh[k + 5].x = wh[k].x;
						wh[k].y = i;
						wh[k].x = j;
						k += 5;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][j] == 0) {
					g[i][j] = -1;
					for (int d = 0; d < 4; d++) 
						ans = MAX(ans, solve(i + dy[d], j + dx[d], d));
					g[i][j] = 0;
				}
			}
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}

int solve(int y, int x, int d) {
	int ret = 1;
	int t = g[y][x];
	// º® ºÎºúÈû
	if (y <= 0 || n < y || x <= 0 || n < x)
		d = (d + 2) % 4;
	// ºí·¢È¦
	else if (t == -1)
		return 0;
	// 0
	else if (t == 0)
		ret = 0;
	// 1 ~ 4
	else if (0 < t && t < 5) {
		if (t == d + 1)
			d = (d + 1) % 4;
		else if ((t + 2) % 4 == d)
			d = (d + 3) % 4;
		else
			d = (d + 2) % 4;
	}
	else if (t == 5)
		d = (d + 2) % 4;
	else {
		y = wh[t].y;
		x = wh[t].x;
		ret = 0;
	}
	return ret + solve(y + dy[d], x + dx[d], d);
}