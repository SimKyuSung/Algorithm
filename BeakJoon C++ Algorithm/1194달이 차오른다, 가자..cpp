/// 1194달이 차오른다, 가자.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector <vector <char> > maze;
vector <vector < vector <bool> > > ch;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct info {
	int x, y, key, cnt;
};

queue <info> q;

int bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	maze.resize(n, vector <char>(m));
	ch.resize(n, vector <vector<bool> >(m, vector <bool>(64, true)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0') {
				q.push({ j, i, 0, 0 });
				ch[i][j][0] = false;
			}
		}
	}
	cout << bfs() << endl;
}

int bfs() {
	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;
		int key = q.front().key;
		int cnt = q.front().cnt + 1;
		q.pop();
		// cout << xx << " " << yy << " " << key << " " << cnt - 1 << endl;
		for (int i = 0; i < 4; i++) {
			int x = xx + dx[i];
			int y = yy + dy[i];
			if (y < 0 || n <= y || x < 0 || m <= x || maze[y][x] == '#')
				continue;
			else if ('A' <= maze[y][x] && maze[y][x] <= 'F') {
				if (((key >> (maze[y][x] - 'A')) & 1) == 0)
					continue;
			}
			else if ('a' <= maze[y][x] && maze[y][x] <= 'f') {
				key |= 1 << (maze[y][x] - 'a');
			}
			else if (maze[y][x] == '1') {
				return cnt;
			}
			if (ch[y][x][key]) {
				q.push({ x, y, key, cnt });
				ch[y][x][key] = false;
			}
		}
	}
	return -1;
}
