#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct cube {
	int x;
	int y;
	int z;
};

int tomato[100][100][100];
int M, N, H;
int lastDay;

int moveX[6] = { 1, -1, 0, 0, 0, 0 };
int moveY[6] = { 0, 0, 1, -1, 0, 0 };
int moveZ[6] = { 0, 0, 0, 0, 1, -1 };
int tomatoCounter = 0;

queue< pair<cube, int> > q;
pair<cube, int> p;

void tomatoMove(cube, int);
bool range_error1(int, int, int);

int main()
{
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++) 
			for (int k = 0; k < M; k++){
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0)
					tomatoCounter++;
				if (tomato[i][j][k] == 1) {
					tomato[i][j][k] = -1;
					p.first.x = k;
					p.first.y = j;
					p.first.z = i;
					p.second = 0;
					q.push(p);
				}
			}

	// 토마토 전진!
	while (!q.empty()) {
		tomatoMove(q.front().first, q.front().second);
		q.pop();
		if (q.size() == 1)
			lastDay = q.front().second;
	}

	if (tomatoCounter == 0)
		cout << lastDay << endl;
	else
		cout << -1 << endl;
}


void tomatoMove(cube c, int day) {
	day++;
	for (int i = 0; i < 6; i++) {
		// 아웃오브 배열 검사 && 캐시 검사.
		if (range_error1(c.x + moveX[i], c.y + moveY[i], c.z + moveZ[i])) {
			p.first.x = c.x + moveX[i];
			p.first.y = c.y + moveY[i];
			p.first.z = c.z + moveZ[i];
			p.second = day;
			tomato[p.first.z][p.first.y][p.first.x] = -1;
			q.push(p);
			tomatoCounter--;
		}
	}
}

bool range_error1(int x, int y, int z) {
	return  ((x < M) &&
		(x >= 0) &&
		(y < N) &&
		(y >= 0) &&
		(z < H) &&
		(z >= 0) &&
		(tomato[z][y][x] != -1));
}