/// 12100_2048(Easy)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

const int maxLv = 5;
int n, a;

//			  u  r   d  l
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int dsx[4] = { 0, 1, 1, 0 };
int dsy[4] = { 0, 0, 1, 1 };

vector <vector < unsigned char> > tile[11];
int counter[20];

unsigned char dfs(int);
void move(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 입력: 2^x 로 저장
	cin >> n;
	for (int lv = 0; lv < 11; lv++) {
		tile[lv].resize(n);
		for (int i = 0; i < n; i++)
			tile[lv][i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			unsigned char tmp = 0;
			while (a) {
				a >>= 1;
				tmp++;
			}
			tile[0][i][j] = tmp;
		}
	}

	// DFS
	cout << (1 << (dfs(0) - 1)) << '\n';
}

// dfs
unsigned char dfs(int lv) {
	// 0. 테스트 출력
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		cout << (int)tile[lv][i][j] << ' ';
	//	cout << endl;
	//}
	//cout << endl;

	unsigned char ans = 0;
	// 1. 종료조건
	if (lv == maxLv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				ans = max(ans, tile[lv][i][j]);
		}
		return ans;
	}

	for (int d = 0; d < 4; d++) {
		// 2-1 다음 만들기
		move(d, lv);
		// 2-2 다음 턴이 최대값 갱신 가능성이 있는지 판별
		for (int c = 19; c > 0; c--)
			counter[c] += counter[c + 1] * 2;

		// lv.5에서 x를 초과 하기 위해서는
		// lv 에서 x		2개 이상 -> [x >> (5 - lv - 1)]를 [1 << (5 - lv)]개 이상
		if (ans == 0 || counter[ans + lv - maxLv + 1] >= (1 << (maxLv - lv)))
			ans = max(ans, dfs(lv + 1));
	}
	return ans;
}

// d 방향으로 움직임
void move(int d, int lv) {
	memset(counter, 0, sizeof(counter));
	int xs = dsx[d] * (n - 1);
	int ys = dsy[d] * (n - 1);
	for (int i = 0; i < n; i++) {
		int x = xs, y = ys;
		int index = x, indey = y;
		int num = 0;
		for (int j = 0; j < n; j++) {
			tile[lv + 1][y][x] = 0;
			if (tile[lv][y][x]) {
				// 1. 같은 블럭 합치기
				if (tile[lv][y][x] == num) {
					index -= dx[d];
					indey -= dy[d];
					tile[lv + 1][indey][index]++;
					num = 0;
				}
				else {
					num = tile[lv][y][x];
					tile[lv + 1][indey][index] = num;
				}
				counter[tile[lv + 1][indey][index]]++;
				index += dx[d];
				indey += dy[d];
			}
			x += dx[d];
			y += dy[d];
		}
		xs += dx[(d + 3) % 4];
		ys += dy[(d + 3) % 4];
	}
}

/*

0 2 4 8 16 32 64 128 256 512 1024
만들수 있는 최대값 : 1048576 -> 2 ^ 20

5턴에서 13 일때

13보다 큰 값을 만들기 위해서는
4턴에 13이 2개 이상 있어야 한다.
3턴에 12가 4개 이상 || (12 * 2) + 13
2턴에 11이 8개 이상
1턴에 10이 16개 이상 존재 해야 한다.


*/