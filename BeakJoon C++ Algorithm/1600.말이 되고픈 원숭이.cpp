/// 1600.¸»ÀÌ µÇ°íÇÂ ¿ø¼şÀÌ

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int dx2[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy2[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

bool check[200][200][31];

struct Monkey {
	int y, x;
	int k, counter;
};
queue <Monkey> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, w, h;
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int foo;
			cin >> foo;
			for (int c = 0; c <= k; c++)
				check[i][j][c] = foo;
		}
	}

	q.push({ 0, 0, k, 0 });
	for (int c = 0; c < k; c++)
		check[0][0][c] = 1;

	while (!q.empty()) {
		Monkey now = q.front();
		q.pop();

		int x = now.x;
		int y = now.y;
		k = now.k;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && !check[ny][nx][k]) {
				if (nx == w - 1 && ny == h - 1) {
					cout << now.counter + 1 << endl;
					return 0;
				}
				check[ny][nx][k] = 1;
				q.push({ ny, nx, k, now.counter + 1 });
			}
		}
		if (k) {
			for (int d = 0; d < 8; d++) {
				int nx = x + dx2[d];
				int ny = y + dy2[d];
				if (0 <= nx && nx < w && 0 <= ny && ny < h && !check[ny][nx][k - 1]) {
					if (nx == w - 1 && ny == h - 1) {
						cout << now.counter + 1 << endl;
						return 0;
					}
					check[ny][nx][k - 1] = 1;
					q.push({ ny, nx, k - 1, now.counter + 1 });
				}
			}
		}
	}
	cout << -1 << endl;

}

/*

0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

0. 
0 0 0 0 0 0 1
0 0 0 0 0 1 0
0 0 0 0 1 0 0
0 0 0 1 0 0 0
0 0 1 0 0 0 0
0 1 0 0 0 0 0
1 0 0 0 0 0 0

1. 
1 1 0 0 0 0 1
1 0 x 0 0 1 0
0 x 0 0 1 0 0
0 0 0 1 0 0 0
0 0 1 0 0 0 0
0 1 0 0 0 0 0
1 0 0 0 0 0 0

2. 
1 1 1 0 0 0 1
1 1 x x 0 1 0
1 x x 0 1 0 0
0 x 0 1 0 0 0
0 0 1 0 0 0 0
0 1 0 0 0 0 0
1 0 0 0 0 0 0

3.
1 1 1 1 0 0 1
1 1 x x x 1 0
1 x x x 1 0 0
1 x x 1 0 0 0
0 x 1 0 0 0 0
0 1 0 0 0 0 0
1 0 0 0 0 0 0


*/