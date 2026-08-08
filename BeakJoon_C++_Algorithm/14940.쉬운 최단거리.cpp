/// 14940.쉬운 최단거리

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

struct Point {
	unsigned short y, x;
	int v;
};
const short dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int ans[1000][1000];

queue <Point> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(ans, -1, sizeof(ans));
	int n, m;
	unsigned short i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int input;
			cin >> input;
			if (input == 2) {
				q.push({ i, j, 0 });
				ans[i][j] = 0;
			}
			else if (input == 0)
				ans[i][j] = 0;
		}
	}
	while (!q.empty()) {
		Point point = q.front();
		int x = point.x, y = point.y, ret = point.v;
		q.pop();
		for (int d = 0; d < 4; d++) {
			unsigned short xx = x + dx[d], yy = y + dy[d];
			if (0 <= xx && xx < m && 0 <= yy && yy < n && ans[yy][xx] == -1) {
				ans[yy][xx] = ret + 1;
				q.push({ yy, xx, ret + 1 });
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}

}