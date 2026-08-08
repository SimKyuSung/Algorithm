/// 7576≈‰∏∂≈‰
/// 2018-01-31 by Sim_kyuSung

#include <iostream>
#include <queue>

using namespace std;

int box[1000][1000];

struct Tomato{
	int x, y, day;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

queue <Tomato> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int &a = box[i][j];
			cin >> a;
			if (a == 1)
				q.push({ j, i, 1 });
		}
	}

	int lastDay = 0;
	while (!q.empty()) {
		Tomato now = q.front();
		q.pop();
		int day = now.day;
		lastDay = day - 1;

		for (int d = 0; d < 4; d++) {
			int x = now.x + dx[d];
			int y = now.y + dy[d];
			if (0 <= x && x < m && 0 <= y && y < n && box[y][x] == 0) {
				q.push({ x, y, day + 1 });
				box[y][x] = day + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			if (box[i][j] == 0)
				lastDay = -1;
	cout << lastDay << endl;
}