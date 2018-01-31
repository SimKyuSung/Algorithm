/// 7569≈‰∏∂≈‰
/// 2018-01-31 by Sim_kyuSung

#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100];

struct Tomato {
	int x, y, z, day;
};

int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue <Tomato> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, h;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int &a = box[i][j][k];
				cin >> a;
				if (a == 1)
					q.push({ k, j, i, 1 });
			}
		}
	}

	int lastDay = 0;
	while (!q.empty()) {
		Tomato now = q.front();
		q.pop();
		int day = now.day;
		lastDay = day - 1;

		for (int d = 0; d < 6; d++) {
			int x = now.x + dx[d];
			int y = now.y + dy[d];
			int z = now.z + dz[d];
			if (0 <= x && x < m && 0 <= y && y < n && 0 <= z && z < h && box[z][y][x] == 0) {
				q.push({ x, y, z, day + 1 });
				box[z][y][x] = day + 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (box[i][j][k] == 0)
					lastDay = -1;
	}
	cout << lastDay << endl;
}