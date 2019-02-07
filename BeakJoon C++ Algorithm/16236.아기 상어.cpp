/// 16236.아기 상어

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

struct Point {
	int y, x, t;
};

bool cmp(Point a, Point b) {
	if (a.t == b.t) {
		if (a.y == b.y)
			return a.x < b.x;
		else
			return a.y < b.y;
	}
	return a.t < b.t;
}

int water[20][20];
bool check[20][20];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

queue <Point> q;
vector <Point> fishList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> water[i][j];
			if (water[i][j] == 9) {
				water[i][j] = 0;
				q.push({ i, j, 0 });
			}
		}
	}


	int y, x, t, gSize = 2, counter = 2, ans = 0;
	while (1) {
		// 0. init
		memset(check, 0, sizeof(check));
		check[q.front().y][q.front().x] = 1;
		fishList.clear();

		// 1. 물고기 찾기
		while (!q.empty()) {
			Point now = q.front();
			q.pop();
			y = now.y;
			x = now.x;
			t = now.t;
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (0 <= ny && ny < n && 0 <= nx && nx < n && water[ny][nx] <= gSize && !check[ny][nx]) {
					check[ny][nx] = 1;
					q.push({ ny, nx, t + 1 });
					if (water[ny][nx] != 0 && water[ny][nx] < gSize)
						fishList.push_back({ ny, nx, t + 1 });
				}
			}
		}

		// 2. 먹을거 없으면 여행 끝
		if (fishList.empty())
			break;

		// 3. 가장 가까운 물고기 먹기
		sort(fishList.begin(), fishList.end(), cmp);
		y = fishList[0].y;
		x = fishList[0].x;
		q.push({ y, x, 0 });
		water[y][x] = 0;
		ans += fishList[0].t;

		// 4. 물고기 성장
		counter--;
		if (counter == 0) {
			gSize++;
			counter = gSize;
		}
	}
	cout << ans << endl;
}