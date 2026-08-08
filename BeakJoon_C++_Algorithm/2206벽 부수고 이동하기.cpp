/// 2206벽 부수고 이동하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector < vector <bool> > Tmap;
vector < vector <bool> > dp[2];

struct Coordinate {
	int x, y, wall, counter;
};

queue <Coordinate> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	char input;
	cin >> n >> m;

	Tmap.resize(n, vector <bool>(m, 0));
	dp[0].resize(n, vector <bool>(m, 0));
	dp[1].resize(n, vector <bool>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			Tmap[i][j] = input - '0';
		}
	}

	dp[0][0][0] = 1;
	q.push({ 0, 0, 0, 1 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		int counter = q.front().counter;
		q.pop();
		//cout << x << y << endl;
		if (x == m - 1 && y == n - 1) {
			cout << counter << endl;
			return 0;
		}
		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < m && 0 <= yy && yy < n) {
				int nw = wall + Tmap[yy][xx];
				if (nw < 2 && !dp[nw][yy][xx]) {
					dp[nw][yy][xx] = 1;
					q.push({ xx, yy, nw, counter + 1 });
				}
			}
		}
	}
	cout << -1 << endl;
}