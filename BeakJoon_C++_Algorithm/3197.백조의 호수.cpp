/// 3197.백조의 호수

#include <iostream>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int r, c;
int lake[1500][1500];
struct Point {
	int y, x, day;
};

bool operator < (Point a, Point b) {
	return a.day > b.day;
}
queue <Point> q;
priority_queue <Point> pq;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Point s[2];
	int p = 0;

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char l;
			lake[i][j] = -1;
			cin >> l;
			if (l != 'X') {
				if (l == 'L')
					s[p++] = { i, j, 0 };
				q.push({ i, j, 0 });
				lake[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << lake[i][j] << ' ';
		cout << endl;
	}

	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (0 <= ny && ny < r && 0 <= nx && nx < c && lake[ny][nx] == -1) {
				lake[ny][nx] = now.day + 1;
				q.push({ ny, nx, now.day + 1 });
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << lake[i][j] << ' ';
		cout << endl;
	}

	pq.push(s[0]);
	lake[s[0].y][s[0].x] = -1;
	while (!pq.empty()) {
		Point now = pq.top();
		pq.pop();
		if (now.x == s[1].x && now.y == s[1].y) {
			cout << now.day << endl;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (0 <= ny && ny < r && 0 <= nx && nx < c && lake[ny][nx] != -1) {
				pq.push({ ny, nx, max(lake[ny][nx], now.day) });
				lake[ny][nx] = -1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << lake[i][j] << ' ';
		cout << endl;
	}
}