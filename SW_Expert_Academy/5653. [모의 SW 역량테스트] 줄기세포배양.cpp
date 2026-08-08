/// 5653. [모의 SW 역량테스트] 줄기세포배양

#include <iostream>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

short grid[351][351];
short cellTime[351][351];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

short yList[2000];
short xList[2000];
short cList[2000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, k, ans = 0;
		short y, x;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				short tmp;
				cin >> tmp;
				grid[i + 150][j + 150] = tmp;
				cellTime[i + 150][j + 150] = tmp;
			}
		}
		while (k--) {
			int counter = 0;

			for (int i = 0; i < 351; i++) {
				for (int j = 0; j < 351; j++) {
					//cout << i << '?' << j << endl;
					if (cellTime[i][j] == 0 && grid[i][j] != 0) {
						for (int d = 0; d < 4; d++) {
							y = i + dy[d];
							x = j + dx[d];
							//cout << y - 310 << ' ' << x - 310 << endl;
							if (grid[y][x] == 0) {
								yList[counter] = y;
								xList[counter] = x;
								cList[counter] = grid[i][j];
								counter++;
								//grid[y][x] = grid[i][j];
								//cellTime[y][x] = grid[i][j];
							}
						}
					}
					if (grid[i][j] > 0)
						cellTime[i][j]--;
					if (grid[i][j] != 0 && grid[i][j] == -cellTime[i][j])
						grid[i][j] = -1;
					
				}
			}
			while (counter--) {
				y = yList[counter];
				x = xList[counter];
				grid[y][x] = max(grid[y][x], cList[counter]);
				cellTime[y][x] = max(cellTime[y][x], cList[counter]);
			}
			/*for (int i = 300; i < n + 320; i++) {
				for (int j = 300; j < m + 320; j++)
					cout << grid[i][j] << '\t';
				cout << endl;
			}
			cout << endl;*/
		}

		for (int i = 0; i < 351; i++) {
			for (int j = 0; j < 351; j++) {
				if (grid[i][j] > 0)
					ans++;
				grid[i][j] = 0;
				cellTime[i][j] = 0;
			}
		}
		cout << '#' << t << ' ' << ans << endl;
		memset(grid, 0, sizeof(grid));
	}
}