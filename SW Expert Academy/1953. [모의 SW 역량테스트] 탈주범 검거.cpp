/// 1953. [모의 SW 역량테스트] 탈주범 검거

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

int sewer[50][50];
bool check[50][50];
struct Point {
	int y, x, t;
};

queue <Point> q;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, y, x, l, ans = 1;
		memset(check, 0, sizeof(check));
		cin >> n >> m >> y >> x >> l;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> sewer[i][j];
		
		q.push({ y, x, l });
		check[y][x] = 1;

		while (!q.empty()) {
			Point now = q.front();
			q.pop();
			y = now.y;
			x = now.x;
			if (now.t == 1)
				continue;
			int ny, nx;
			l = now.t - 1;
			ny = y - 1;
			nx = x;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !check[ny][nx] &&
				(sewer[y][x] == 1 || sewer[y][x] == 2 || sewer[y][x] == 4 || sewer[y][x] == 7) &&
				(sewer[ny][nx] == 1 || sewer[ny][nx] == 2 || sewer[ny][nx] == 5 || sewer[ny][nx] == 6)) {
				ans++;
				check[ny][nx] = 1;
				q.push({ ny, nx, l });
			}
			// right
			ny = y;
			nx = x + 1;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !check[ny][nx] &&
				(sewer[y][x] == 1 || sewer[y][x] == 3 || sewer[y][x] == 4 || sewer[y][x] == 5) &&
				(sewer[ny][nx] == 1 || sewer[ny][nx] == 3 || sewer[ny][nx] == 6 || sewer[ny][nx] == 7)) {
				ans++;
				check[ny][nx] = 1;
				q.push({ ny, nx, l });
			}
			// down
			ny = y + 1;
			nx = x;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !check[ny][nx] &&
				(sewer[y][x] == 1 || sewer[y][x] == 2 || sewer[y][x] == 5 || sewer[y][x] == 6) &&
				(sewer[ny][nx] == 1 || sewer[ny][nx] == 2 || sewer[ny][nx] == 4 || sewer[ny][nx] == 7)) {
				ans++;
				check[ny][nx] = 1;
				q.push({ ny, nx, l });
			}
			// left
			ny = y;
			nx = x - 1;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !check[ny][nx] &&
				(sewer[y][x] == 1 || sewer[y][x] == 3 || sewer[y][x] == 6 || sewer[y][x] == 7) &&
				(sewer[ny][nx] == 1 || sewer[ny][nx] == 3 || sewer[ny][nx] == 4 || sewer[ny][nx] == 5)) {
				ans++;
				check[ny][nx] = 1;
				q.push({ ny, nx, l });
			}
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++)
		//		cout << check[i][j] << ' ';
		//	cout << endl;
		//}
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*

up		1 2 4 7
right	1 3 4 5
down	1 2 5 6
left	1 3 6 7



*/