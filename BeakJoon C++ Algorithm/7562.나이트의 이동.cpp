/// 7562.나이트의 이동

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int m[300][300];

struct Point {
	int y, x;
};

void bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;	cin >> tc;
	while (tc--)
		bfs();
}

void bfs() {
	memset(m, -1, sizeof(m));
	int l;
	Point s, e;
	queue <Point> q;

	cin >> l >> s.x >> s.y >> e.x >> e.y;
	if (s.y == e.y && s.x == e.x) {
		cout << 0 << endl;
		return;
	}
	q.push(s);
	m[s.y][s.x] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx < l && 0 <= ny && ny < l && m[ny][nx] == -1) {
				if (e.y == ny && e.x == nx) {
					cout << m[y][x] + 1 << endl;
					return;
				}
				q.push({ ny, nx });
				m[ny][nx] = m[y][x] + 1;
			}
		}
	}
}