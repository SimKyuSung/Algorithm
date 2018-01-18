/// 13459째로탈출

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char maze[10][10];
bool dp[10][10][10][10];
// 남, 북, 서, 동
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

struct coor
{
	int turn;
	int rY, rX;
	int bY, bX;
};

queue <coor> q;

pair<coor, bool> moveRed(int d, coor now) {
	int &x = now.rX;
	int &y = now.rY;
	maze[now.bY][now.bX] = 'B';
	while (maze[y + dy[d]][x + dx[d]] == '.') {
		y += dy[d];
		x += dx[d];
	}
	maze[now.bY][now.bX] = '.';
	if (maze[y + dy[d]][x + dx[d]] == 'O') {
		y = 0;
		x = 0;
		return { now, true };
	}
	else									return { now, false };
}

pair<coor, bool> moveBlue(int d, coor now) {
	int &x = now.bX;
	int &y = now.bY;
	maze[now.rY][now.rX] = 'R';
	while (maze[y + dy[d]][x + dx[d]] == '.') {
		y += dy[d];
		x += dx[d];
	}
	maze[now.rY][now.rX] = '.';
	if (maze[y + dy[d]][x + dx[d]] == 'O') {
		y = 0;
		x = 0;
		return { now, true };
	}
	else									return { now, false };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	coor init;
	init.turn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'R') {
				init.rY = i;
				init.rX = j;
				maze[i][j] = '.';
			}
			else if (maze[i][j] == 'B') {
				init.bY = i;
				init.bX = j;
				maze[i][j] = '.';
			}
		}
	}

	q.push(init);
	dp[init.rY][init.rX][init.bY][init.bX] = true;

	while (!q.empty()) {
		coor now = q.front();
		q.pop();
		/*
		cout << "Red\t" << now.rY << " " << now.rX << endl;
		cout << "Blue\t" << now.bY << " " << now.bX << endl;
		cout << endl;
		*/

		// 움직인 횟수가 10번 이상이라면 중단!
		if (now.turn < 10) {
			for (int d = 0; d < 4; d++) {
				pair <coor, bool> tmp; 
				coor next = now;
				// 공움직임 순서 정하기
				int red = now.rX * dx[d] + now.rY * dy[d];
				int blue = now.bX * dx[d] + now.bY * dy[d];

				// 값이 큰쪽이 기울이는 방향에 더 가까움으로 먼저 움직임
				if (red > blue) {
					tmp = moveRed(d, next);
					next = tmp.first;
					red = tmp.second;

					tmp = moveBlue(d, next);
					next = tmp.first;
					blue = tmp.second;
				}
				else {
					tmp = moveBlue(d, next);
					next = tmp.first;
					blue = tmp.second;

					tmp = moveRed(d, next);
					next = tmp.first;
					red = tmp.second;
				}

				if (red == 1 && blue == 0) {
					cout << 1;
					return 0;
				}
				// 그전에 방문한적이 없고, 블루홀이 아니라면 큐에 넣는다.
				bool &nowState = dp[next.rY][next.rX][next.bY][next.bX];
				if (blue != 1 && !nowState) {
					next.turn++;
					q.push(next);
					nowState = true;
				}
			}
		}
	}
	cout << 0;
}

/*

5 5
#####
#..B#
#.#.#
#RO.#
#####

coor
t	0
r	3, 1
b	1, 3

남 북 서 동
0, 0, -1, 1
1, -1, 0, 0

3, 1
-3, -1
남 일때 x+y 곱해서 큰게 먼저
북 일떼 


*/