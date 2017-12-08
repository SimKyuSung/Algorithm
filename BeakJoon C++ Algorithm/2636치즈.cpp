/// 2636ДЎБо

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int v[102][102];
int c[102][102];
bool ch[102][102];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> v[i][j];

	int h = 0;
	int cheezeCounter;
	while (1) {
		memset(ch, false, sizeof(ch));
		memset(c, 0, sizeof(c));
		int counter = 0;
		cheezeCounter = 0;
		queue <pair<int, int> > q;
		q.push({ 0, 0 });
		ch[0][0] = true;

		while (!q.empty()) {
			for (int d = 0; d < 4; d++) {
				int x = q.front().first + dx[d];
				int y = q.front().second + dy[d];
				if (0 <= x && x <= m + 1 && 0 <= y && y <= n + 1) {
					if (!ch[y][x] && v[y][x] == 0) {
						q.push({ x, y });
						ch[y][x] = true;
					}
					else if (v[y][x]) {
						c[y][x]++;
					}
				}
			}
			q.pop();
		}
		//cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (c[i][j] > 0) {
					v[i][j] = 0;
					cheezeCounter++;
				}
				if (v[i][j] == 0)
					counter++;
				//cout << v[i][j] << " ";
			}
			//cout << endl;
		}
		h++;
		if (counter == n * m)	break;
		
	}
	cout << h << endl;
	cout << cheezeCounter << endl;
}