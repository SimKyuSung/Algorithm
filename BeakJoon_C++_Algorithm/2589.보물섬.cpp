/// 2589.º¸¹°¼¶

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'
#define MAX(a, b) (a)>(b)?(a):(b)

using namespace std;

bool isle[52][52], t[52][52];
short dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

struct Point {
	short y, x, counter;
};

queue <Point> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	short n, m, i, j, ans = 0, x, y, d;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			char input;
			cin >> input;
			if (input == 'L')
				isle[i][j] = 1;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (isle[i][j]) {
				if (isle[i - 1][j] && isle[i + 1][j])
					continue;
				if (isle[i][j - 1] && isle[i][j + 1])
					continue;
				memcpy(t, isle, sizeof(t));
				t[i][j] = 0;
				q.push({ i, j, 0 });
				while (!q.empty()) {
					Point tmp = q.front();
					q.pop();
					ans = MAX(ans, tmp.counter);

					for (d = 0; d < 4; d++) {
						x = tmp.x + dx[d];
						y = tmp.y + dy[d];
						if (0 <= x && x < m && 0 <= y && y < n && t[y][x]) {
							t[y][x] = 0;
							q.push({ y, x, tmp.counter + 1 });
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}
