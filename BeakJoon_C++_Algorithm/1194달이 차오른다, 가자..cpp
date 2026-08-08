/// 1194달이 차오른다, 가자.

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int n, m;

vector <vector <char> > maze;
vector <vector < bitset<255> > > ch;

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
	ch.resize(n, vector < bitset<255> >(m, bitset<255>(0)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0') {
				q.push({ j, i, 0, 0 });
				maze[i][j] = '.';
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
		for (int i = 0; i < 4; i++) {
			int x = xx + dx[i];
			int y = yy + dy[i];
			int nextKey = key;

			if (y < 0 || n <= y || x < 0 || m <= x || maze[y][x] == '#')
				continue;
			else if ('A' <= maze[y][x] && maze[y][x] <= 'F') {
				if (((nextKey >> (maze[y][x] - 'A')) & 1) == 0)
					continue;
			}
			else if ('a' <= maze[y][x] && maze[y][x] <= 'f') {
				nextKey |= (1 << (maze[y][x] - 'a'));
			}
			else if (maze[y][x] == '1') {
				return cnt;
			}

			// 다른키를 가지고 있으면 푸쉬
			if (!ch[y][x][nextKey]) {
				q.push({ x, y, nextKey, cnt });
				ch[y][x][nextKey] = 1;
			}
		}
	}
	return -1;
}

/*
tc


*/