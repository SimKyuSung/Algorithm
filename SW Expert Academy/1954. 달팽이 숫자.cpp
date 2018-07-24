/// 1954. 달팽이 숫자

#include <iostream>
#include <memory.h>

using namespace std;

int snail[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(snail, 0, sizeof(snail));
		
		int n, i = 1, d = 0, x = 0, y = 0;
		cin >> n;
		while (i != n * n + 1) {
			snail[y][x] = i;
			x += dx[d];
			y += dy[d];
			if (0 > x || x >= n || 0 > y || y >= n || snail[y][x] != 0) {
				x -= dx[d];
				y -= dy[d];
				d++;
				d = d % 4;
				x += dx[d];
				y += dy[d];
			}
			i++;
		}

		cout << '#' << t << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << snail[i][j] << ' ';
			cout << '\n';
		}

	}
}