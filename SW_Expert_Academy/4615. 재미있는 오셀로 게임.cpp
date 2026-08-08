/// 4615. 재미있는 오셀로 게임

#include <iostream>
#include <memory.h>

#define endl '\n'

using namespace std;

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int board[8][8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(board, 0, sizeof(board));
		int n, m;
		cin >> n >> m;
		board[n / 2 - 1][n / 2 - 1] = board[n / 2][n / 2] = 2;
		board[n / 2 - 1][n / 2] = board[n / 2][n / 2 - 1] = 1;
		while (m--) {
			int x, y, bw;
			cin >> x >> y >> bw;
			x--;
			y--;
			board[y][x] = bw;
			for (int d = 0; d < 8; d++) {
				int xx = x + dx[d], yy = y + dy[d];
				int xxx, yyy;
				bool flag = 0;
				while (0 <= xx && xx < n && 0 <= yy && yy < n && board[yy][xx] != 0) {
					if (board[yy][xx] == bw) {
						flag = 1;
						xxx = xx;
						yyy = yy;
						break;
					}
					xx += dx[d];
					yy += dy[d];
				}
				if (flag) {
					xx = x;
					yy = y;
					while (xx != xxx || yy != yyy) {
						board[yy][xx] = bw;
						xx += dx[d];
						yy += dy[d];
					}
				}
			}
			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < n; j++) {
			//		cout << board[i][j];
			//	}
			//	cout << endl;
			//}
		}
		int black = 0, white = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				black += board[i][j] == 1;
				white += board[i][j] == 2;
			}
		}
		cout << '#' << t << ' ' << black << ' ' << white << endl;
	}
}

/*

	1	2	3	4
1	2	2	2	2
2	2	2	2	2
3	2	2	2	2
4	2	2	2	2

*/