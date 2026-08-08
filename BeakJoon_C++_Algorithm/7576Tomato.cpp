#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>

using namespace std;

short tomato[1000][1000];
int N, M;
int lastDay;

bool cash[1000][1000];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };

int tomatoCounter = 0;

queue< pair< pair<int, int>, int> > q;
pair<pair<int, int>, int> p;

void tomatoMove(int, int, int);
bool range_error1(int, int);

int main()
{
	cin >> N >> M;
	
	// m행 입력
	for (int i = 0; i < M; i++)
		// n 열 입력
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 0)
				tomatoCounter++;
			if (tomato[i][j] == 1) {
				cash[i][j] = true;
				p.first.first = i;
				p.first.second = j;
				p.second = 0;
				q.push(p);
			}
			if (tomato[i][j] == -1) {
				cash[i][j] = true;
			}
		}
	// 토마토 전진!
	while (!q.empty()) {
		tomatoMove(q.front().first.first, q.front().first.second, q.front().second);
		q.pop();
		if (q.size() == 1)
			lastDay = q.front().second;
	}

	if (tomatoCounter == 0)
		cout << lastDay << endl;
	else
		cout << -1 << endl;
}


void tomatoMove(int x, int y, int day) {
	day++;
	for (int i = 0; i < 4; i++) {
		// 아웃오브 배열 검사 && 캐시 검사.
		if (range_error1(x + moveX[i], y + moveY[i])) {
			p.first.first = x + moveX[i];
			p.first.second = y + moveY[i];
			p.second = day;
			q.push(p);
			cash[x + moveX[i]][y + moveY[i]] = true;
			tomatoCounter--;
		}
	}
}

bool range_error1(int x, int y) {
	return  ((x < M) &&
		(x >= 0) &&
		(y < N) &&
		(y >= 0) &&
		(tomato[x][y] != -1) &&
		(!cash[x][y]));
}