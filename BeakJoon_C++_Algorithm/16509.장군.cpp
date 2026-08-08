/// 16509.¿Â±∫

//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int dx[8][3] = {
	{ -1, -1, -1},
	{  0, -1, -1},
	{  0,  1,  1},
	{  1,  1,  1},
	{  1,  1,  1},
	{  0,  1,  1},
	{  0, -1, -1},
	{ -1, -1, -1}
};
int dy[8][3] = {
	{  0, -1, -1},
	{ -1, -1, -1},
	{ -1, -1, -1},
	{  0, -1, -1},
	{  0,  1,  1},
	{  1,  1,  1},
	{  1,  1,  1},
	{  0,  1,  1}
};

bool check[10][9];
queue <int> q;

int main()
{
	// init
	ios::sync_with_stdio(false);
	cin.tie(0);

	int kr, kc, er, ec;
	cin >> er >> ec >> kr >> kc;

	// solve
	int ans = 1;
	check[er][ec] = 1;
	q.push(er * 10 + ec);
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int y = q.front() / 10;
			int x = q.front() % 10;
			q.pop();

			for (int d = 0; d < 8; d++) {
				int ny = y;
				int nx = x;

				bool flag = 0;
				for (int t = 0; t < 2; t++) {
					ny += dy[d][t];
					nx += dx[d][t];
					//cout << ny << ' ' << nx << endl;
					if (ny == kr && nx == kc) {
						flag = 1;
						break;
					}
				}
				if (flag)
					continue;

				ny += dy[d][2];
				nx += dx[d][2];
				if (kr == ny && kc == nx) {
					cout << ans << endl;
					return 0;
				}
				if (0 <= ny && ny < 10 && 0 <= nx && nx < 9 && !check[ny][nx]) {
					check[ny][nx] = 1;
					q.push(10 * ny + nx);
				}
			}
		}
		ans++;
	}
	cout << -1 << endl;
}

/*
error input
0 2
1 4

wa output
3

ac output
5


*/