/// 1873. 상호의 배틀필드

#include <iostream>
#include <string>

using namespace std;

int h, w;
char a[20][20];

int x, y, d;

int n;
string cmd;

			// u  d  l  r
int dx[4] = { 0, 0 ,-1, 1 };
int dy[4] = { -1, 1 ,0, 0 };

int dir[128];
char chToint[2][4] = {
	{ '^', 'v', '<', '>' },
	{ 'U', 'D', 'L', 'R' }
};

void game();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
		dir[chToint[0][i]] = dir[chToint[1][i]] = i;;

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '^' || a[i][j] == 'v' || a[i][j] == '<' || a[i][j] == '>') {
					y = i;
					x = j;
					d = dir[a[i][j]];
					a[i][j] = '.';
				}
			}
		}
		cin >> n >> cmd;
		
		game();
		cout << '#' << t << ' ';
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == y && j == x) {
					cout << chToint[0][d];
				}
				else {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}

void game() {
	for (int pc = 0; pc < n; pc++) {
		char &p = cmd[pc];
		if (p != 'S') {
			d = dir[p];
			y += dy[d];
			x += dx[d];
			if (x < 0 || w <= x || y < 0 || h <= y || a[y][x] != '.') {
				y -= dy[d];
				x -= dx[d];
			}
		}
		else {
			bool shot = 0;
			int sy = y, sx = x;
			while (!shot) {
				sy += dy[d];
				sx += dx[d];
				if (sx < 0 || w <= sx || sy < 0 || h <= sy) {
					shot = 1;
				}
				else if (a[sy][sx] == '*') {
					a[sy][sx] = '.';
					shot = 1;
				}
				else if (a[sy][sx] == '#') {
					shot = 1;
				}
			}
		}
	}
}