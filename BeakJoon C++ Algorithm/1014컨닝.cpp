/// 1014ÄÁ´× + 11014ÄÁ´×2

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int c, n, m;
char test[100][100];

int dx[6] = { -1, -1, -1, 1, 1, 1 };
int dy[6] = { -1,  0,  1,-1, 0, 1 };
bool vi[100][100];

vector < vector < pair <int, int> > > odd;

vector < vector < vector < pair<int, int> > > > edge;

bool dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c;

	while (c--) {
		int ans = 0;

		cin >> n >> m;
		edge = vector <vector < vector < pair<int, int> > > >(n, vector< vector < pair<int, int> >>(m));
		odd = vector<vector<pair<int, int> > >(n, vector<pair<int, int> >(m, { -1, -1 }));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> test[i][j];
				ans -= (test[i][j] == 'x');
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j += 2) {
				edge[i][j].clear();
				if (test[i][j] == '.') {
					for (int d = 0; d < 6; d++) {
						int nx = j + dx[d];
						int ny = i + dy[d];
						if (0 <= nx && nx < m && 0 <= ny && ny < n && test[ny][nx] == '.')
							edge[i][j].push_back({ ny, nx });
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j += 2) {
				memset(vi, 0, sizeof(vi));
				ans -= dfs(i, j);
			}
		}
		cout << n * m + ans << '\n';
	}
}

bool dfs(int y, int x) {
	vi[y][x] = true;
	for (auto p : edge[y][x]) {
		int i = p.first, j = p.second;
		if (odd[i][j].first == -1) {
			odd[i][j] = { y, x };
			return true;
		}
		else if (!vi[odd[i][j].first][odd[i][j].second] &&
				 dfs(odd[i][j].first, odd[i][j].second)) {
			odd[i][j] = { y, x };
			return true;
		}
	}
	return false;
}



/*

10 10
....x.....
..........
..........
..x.......
..........
x...x.x...
.........x
...x......
........x.
.x...x....

[10][1024]

[9][682]

xxxx	all

xxx.	¿ÞÂÊÀ¸·Î 


*/