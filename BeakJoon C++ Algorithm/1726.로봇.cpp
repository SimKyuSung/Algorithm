/// 1726.로봇

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int n, m;
bool check[101][101][4];
bool wall[101][101];

struct State {
	int y, x, d, counter;
};

// 동 북 서 남
/*
	북1
서2		동0
	남3

*/
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

queue <State> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int w = 0;
			cin >> w;
			wall[i][j] = w;
		}
	}

	int y, x, d;
	cin >> y >> x >> d;
	if (d == 1) d = 0;
	else if (d == 4) d = 1;
	State init = { y, x, d, 0 };
	check[y][x][d] = 1;

	cin >> y >> x >> d;
	if (d == 1) d = 0;
	else if (d == 4) d = 1;
	State target = { y, x, d, 0 };

	q.push(init);
	while (!q.empty()) {
		State now = q.front();
		q.pop();
		y = now.y;
		x = now.x;
		d = now.d;
		int counter = now.counter + 1;
		// * 문제 주의 할점: 시작점과 도착점이 같을 수 있음
		if (target.y == y && target.x == x && target.d == d) {
			cout << now.counter << endl;
			return 0;
		}

		//cout << y << ' ' << x << ' ' << d << ' ' << counter - 1 << endl;

		// 전진 하거나 
		for (int i = 1; i < 4; i++) {
			int ny = y + dy[d] * i;
			int nx = x + dx[d] * i;

			if (0 < ny && ny <= n && 0 < nx && nx <= m) {
				if (wall[ny][nx])
					break;
				if (!check[ny][nx][d]) {
					check[ny][nx][d] = 1;
					q.push({ ny, nx, d, counter });
				}
			}
			else
				break;
		}

		// 회전 하거나
		// ccw
		d = (d + 1) % 4;
		if (!check[y][x][d]) {
			check[y][x][d] = 1;
			q.push({ y, x, d, counter });
		}

		// cw
		d = (d + 2) % 4;
		if (!check[y][x][d]) {
			check[y][x][d] = 1;
			q.push({ y, x, d, counter });
		}
	}
}