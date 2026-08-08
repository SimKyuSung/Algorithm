/// 16234.인구 이동

#include <iostream>
#include <memory.h>
#include <queue>
#include <cmath>

#define endl '\n'

using namespace std;

int n, l, r;
int a[50][50];
bool visited[50][50];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool solve();
bool bfs(int, int);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	l--;
	r++;

	int ans = 0;
	while (solve())
		ans++;
	cout << ans << endl;
}

bool solve() {
	bool ret = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
				ret |= bfs(i, j);
		}
	}
	return ret;
}



struct City {
	int y, x;
}cityList[2500];
queue <City> q;

bool bfs(int y, int x) {
	int counter = 1, sum = 0;

	q.push({ y, x });
	visited[y][x] = 1;
	
	cityList[0] = { y, x };
	sum = a[y][x];

	while (!q.empty()) {
		City now = q.front();
		q.pop();
		y = now.y;
		x = now.x;

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && !visited[ny][nx]) {
				int gap = abs(a[y][x] - a[ny][nx]);
				if (l < gap && gap < r) {
					q.push({ ny, nx });
					visited[ny][nx] = 1;


					cityList[counter] = { ny, nx };
					sum += a[ny][nx];
					counter++;
				}
			}
		}
	}
	for (int i = 0; i < counter; i++) {
		y = cityList[i].y;
		x = cityList[i].x;
		a[y][x] = sum / counter;
	}
	return counter > 1;
}