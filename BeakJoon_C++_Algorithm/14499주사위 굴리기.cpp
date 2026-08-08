/// 14499주사위 굴리기

#include <iostream>

#define endl '\n'

using namespace std;

int n, m, x, y, k, i, j, cmd;
int map[20][20];
int dice[6];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void diceMove(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> map[i][j];

	while (k--) {
		cin >> cmd;
		cmd--;
		int xx = x + dx[cmd];
		int yy = y + dy[cmd];
		if (0 <= xx && xx < n && 0 <= yy && yy < m) {
			x = xx;
			y = yy;
			diceMove(cmd);
			if (map[x][y]) {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = dice[5];
			cout << dice[0] << '\n';
		}
	}
}

void diceMove(int cmd) {
	int tmp;
	if (cmd == 0) {
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	if (cmd == 1) {
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	if (cmd == 2) {
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	if (cmd == 3) {
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
}