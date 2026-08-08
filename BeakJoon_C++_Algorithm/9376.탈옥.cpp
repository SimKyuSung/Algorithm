/// 9376.Å»¿Á

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Point {
	int y, x;
};

int h, w;
char prison[102][102];
short check[3][102][102];

Point prisoner[3];

void bfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool pp = 0;
		memset(prison, '.', sizeof(prison));
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				char &input = prison[i][j];
				cin >> input;
				if (input == '$') {
					input = '.';
					prisoner[pp++] = { i, j };
				}
			}
		}

		short ans = h * w;
		bfs(0);
		bfs(1);
		bfs(2);
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (prison[i][j] != '*')
					ans = min(ans, short(check[0][i][j] + check[1][i][j] + check[2][i][j] - (prison[i][j] == '#' ? 2 : 0)));
			}
		}
		cout << ans << endl;
	}

}

void bfs(int p) {
	memset(check[p], -1, sizeof(check[p]));

	Point &a = prisoner[p];
	deque <Point> pq;
	pq.push_front(a);
	check[p][a.y][a.x] = 0;

	unsigned int ret = h * w;
	while (!pq.empty()) {
		int x = pq.front().x;
		int y = pq.front().y;
		pq.pop_front();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx <= w + 1 && 0 <= ny && ny <= h + 1) {
				if (prison[ny][nx] != '*' && check[p][ny][nx] == -1) {
					if (prison[ny][nx] != '#') {
						check[p][ny][nx] = check[p][y][x];
						pq.push_front({ ny, nx });
					}
					else {
						check[p][ny][nx] = check[p][y][x] + 1;
						pq.push_back({ ny, nx });
					}
				}
			}
		}
	}
	return;
}