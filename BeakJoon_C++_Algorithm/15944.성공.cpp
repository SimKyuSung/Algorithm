/// 15944.성공

#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

#define endl '\n'

using namespace std;

bool path[500][500];
int boomCnt[500][500];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct Point {
	int y, x;
};
struct Effect {
	Point a;
	Point b;
};
queue <Point> q;
queue <Effect> nextArea;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(boomCnt, 0, sizeof(boomCnt));

	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char input;
			cin >> input;
			path[i][j] = (input == '.');
		}
	}

	if (n == 1 && m == 1) {
		cout << 0 << endl;
		return 0;
	}
	q.push({ 0, 0 });
	nextArea.push({ {0,0},{0,0} });
	boomCnt[0][0] = 1;

	while (1) {
		// 뚫린길 찾기
		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();
			nextArea.push({ {y,x},{y,x} });

			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				// 범위 안에 있고,								방문한적 없고, 길이 뚫린곳
				if (0 <= ny && ny < n && 0 <= nx && nx < m && boomCnt[ny][nx] == 0 && path[ny][nx]) {
					if (ny == n - 1 && nx == m - 1) {
						cout << boomCnt[y][x] - 1 << endl;
						return 0;
					}
					boomCnt[ny][nx] = boomCnt[y][x];
					q.push({ ny, nx });
				}
			}
		}

		// 접근 가능 영역 주변 폭탄 터트리기!
		while (!nextArea.empty()) {
			Effect now = nextArea.front();
			nextArea.pop();

			int y = now.b.y;
			int x = now.b.x;
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				int ndy = abs(now.a.y - ny);
				int ndx = abs(now.a.x - nx);
				// 범위안에 있고,	 방문한적 없고, 소스(a)로 부터 폭탄 1개로 갈수 있는 곳
				if (0 <= ny && ny < n && 0 <= nx && nx < m && boomCnt[ny][nx] == 0 && ndy <= d && ndx <= d && !(ndy == d && ndx == d)) {
					if (ny == n - 1 && nx == m - 1) {
						cout << boomCnt[y][x] - 1 << endl;
						return 0;
					}
					boomCnt[ny][nx] = boomCnt[now.a.y][now.a.x] + 1;
					nextArea.push({ {now.a.y,now.a.x},{ny,nx} });
					q.push({ ny, nx });
				}

			}
		}
		//cout << "BooM!\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++)
		//		cout << boomCnt[i][j];
		//	cout << endl;
		//}
	}

}

/*

8 9 3
.########
##.....##
######.##
####...##
####.####
#########
####.####
########.



*/