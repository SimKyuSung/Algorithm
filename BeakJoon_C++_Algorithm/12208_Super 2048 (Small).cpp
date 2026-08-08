/// 12208_Super 2048 (Small)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int t, n;
string dir;

//			  u  r   d  l
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int dsx[4] = { 0, 1, 1, 0 };
int dsy[4] = { 0, 0, 1, 1 };

int indexDir[128];

vector < vector <int> > tile(20, vector <int>(20));
vector < vector <int> > nextTile(20, vector <int>(20));

void move(int,const vector < vector <int> >, vector < vector <int> >&);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	indexDir['u'] = 0;
	indexDir['r'] = 1;
	indexDir['d'] = 2;
	indexDir['l'] = 3;

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> dir;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> tile[i][j];

		move(indexDir[dir[0]], tile, nextTile);
		
		cout << "Case #" << tc << ":\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << nextTile[i][j] << " ";
			cout << '\n';
		}
	}
}

// d 방향으로 움직임
void move(int d,const vector < vector <int> > tile, vector < vector <int> > &nextTile) {
	int xs = dsx[d] * (n - 1);
	int ys = dsy[d] * (n - 1);
	for (int i = 0; i < n; i++) {
		int x = xs, y = ys;
		int index = x, indey = y;
		int num = 0;
		for (int j = 0; j < n; j++) {			
			nextTile[y][x] = 0;
			if (tile[y][x]) {
				if (tile[y][x] == num) {
					index -= dx[d];
					indey -= dy[d];
					nextTile[indey][index] <<= 1;
					num = 0;
				}
				else {
					num = tile[y][x];
					nextTile[indey][index] = num;
				}
				index += dx[d];
				indey += dy[d];
			}
			x += dx[d];
			y += dy[d];
		}
		xs += dx[(d + 3) % 4];
		ys += dy[(d + 3) % 4];
	}
}