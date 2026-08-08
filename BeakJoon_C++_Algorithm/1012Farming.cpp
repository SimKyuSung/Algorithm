#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory.h>

using namespace std;

int field[50][50];
int M, N, K;
int counter;

int moveX[4] = { 1, -1, 0, 0};
int moveY[4] = { 0, 0, 1, -1};

queue< pair< int, int> > q;

void bugMove(int, int);
bool range_error1(int, int);

int main()
{
	int T;
	cin >> T;
	while (T > 0) {
		// 입력 시퀸스
		T--;
		cin >> M >> N >> K;
		memset(field, 0, sizeof(field));
		while (K > 0) {
			K--;
			int X, Y;
			cin >> X >> Y;
			field[Y][X] = 1;
		}

		// 벌레 전진!
		counter = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 0)
					continue;
				q.push(make_pair(j, i));
				field[i][j] = 0;
				while (!q.empty()) {
					bugMove(q.front().first, q.front().second);
					q.pop();
				}
				counter++;
			}
		}
		cout << counter << endl;
	}
}


void bugMove(int x, int y) {
	for (int i = 0; i < 4; i++) {
		// 아웃오브 배열 검사 && 캐시 검사.
		int X = x + moveX[i];
		int Y = y + moveY[i];
		if (range_error1(X, Y)) {
			field[Y][X] = 0;
			q.push(make_pair(X, Y));
		}
	}
}

bool range_error1(int x, int y) {
	return  ((x < M) &&
		(x >= 0) &&
		(y < N) &&
		(y >= 0) &&
		(field[y][x] != 0));
}