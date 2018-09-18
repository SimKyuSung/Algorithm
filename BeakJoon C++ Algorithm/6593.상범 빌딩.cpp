/// 6593.»ó¹ü ºôµù

#include <iostream>
#include <queue>

using namespace std;

int l, r, c;
char b[30][30][30];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

struct Point {
	int z, y, x, c;
}s;
void bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0)
			return 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					char &ipt = b[i][j][k];
					cin >> ipt;
					if (ipt == 'S')
						s = { i, j, k, 0 };
				}
			}
		}
		bfs();
	}
}

void bfs() {
	queue <Point> q;
	q.push(s);
	b[s.z][s.y][s.x] = '#';

	while (!q.empty()) {
		s = q.front();
		s.c++;
		q.pop();

		for (int d = 0; d < 6; d++) {
			int nx = s.x + dx[d];
			int ny = s.y + dy[d];
			int nz = s.z + dz[d];
			if (0 <= nz && nz < l && 0 <= ny && ny < r && 0 <= nx && nx < c) {
				char &next = b[nz][ny][nx];
				if (next == 'E') {
					cout << "Escaped in " << s.c << " minute(s).\n";
					return;
				}
				if (next != '#') {
					q.push({ nz, ny, nx, s.c });
					next = '#';
				}
			}
		}
	}
	cout << "Trapped!\n";
}