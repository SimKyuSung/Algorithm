/// 9376Å»¿Á

#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <memory.h>

#define maxDoor 10000
#define f first
#define s second
#define pp pair<int, pair<int, int> >

using namespace std;

char p[100][100];
int dp[100][100];
bool v[100][100];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

priority_queue < pp, vector<pp>, greater<pp> > q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, h, w, ans;
	pair<int, int> a[2];

	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int pCounter = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> p[i][j];
				if (p[i][j] == '$')
					a[pCounter++] = { i, j };
			}
		}

		memset(v, 0, sizeof(v));
		q.push({ 0, a[0] });
		v[a[0].first][a[0].second] = 1;
		while (!q.empty()) {
			int door = q.top().f;
			int xx = q.top().s.s;
			int yy = q.top().s.f;
			q.pop();
			dp[yy][xx] = door;
			cout << xx << " " << yy << endl;
			for (int i = 0; i < 4; i++) {
				int x = xx + dx[i];
				int y = yy + dy[i];
				if (0 <= x && x < w && 0 <= y && y < h && !v[y][x] && p[y][x] != '*') {
					v[y][x] = 1;
					q.push({ door + (p[y][x] == '#'), {y, x} });
				}
			}
		}
		cout << endl;
		memset(v, 0, sizeof(v));
		q.push({ 0, a[1] });
		v[a[1].first][a[1].second] = 1;
		while (!q.empty()) {
			int door = q.top().f;
			int xx = q.top().s.s;
			int yy = q.top().s.f;
			q.pop();
			dp[yy][xx] += door;
			cout << xx << " " << yy << endl;
			for (int i = 0; i < 4; i++) {
				int x = xx + dx[i];
				int y = yy + dy[i];
				if (0 <= x && x < w && 0 <= y && y < h && !v[y][x] && p[y][x] != '*') {
					v[y][x] = 1;
					q.push({ door + (p[y][x] == '#'),{ y, x } });
				}
			}
		}
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++)
		//		cout << dp[i][j] << '\t';
		//	cout << endl;
		//}
		int ans = 10000;
		//for (int i = 0; i < h; i++) {
		//	if (p[i][0] != '*')
		//		ans = min(ans, dp[i][0]);
		//	if (p[i][w - 1] != '*')
		//		ans = min(ans, dp[i][w - 1]);
		//}
		//for (int j = 0; j < w; j++) {
		//	if (p[0][j] != '*')
		//		ans = min(ans, dp[0][j]);
		//	if (p[h - 1][j] != '*')
		//		ans = min(ans, dp[h - 1][j]);
		//}
		cout << ans << '\n';
	}
}
/*

3
5 9
****#****
*..#.#..*
****.****
*$#.#.#$*
*********
5 11
*#*********
*$*...*...*
*$*.*.*.*.*
*...*...*.*
*********.*
9 9
*#**#**#*
*#**#**#*
*#**#**#*
*#**.**#*
*#*#.#*#*
*$##*##$*
*#*****#*
*.#.#.#.*
*********

*/