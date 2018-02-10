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

	// �Է�: 2^x �� ����
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
	// 0. �׽�Ʈ ���
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		cout << (int)tile[lv][i][j] << ' ';
	//	cout << endl;
	//}
	//cout << endl;

	unsigned char ans = 0;
	// 1. ��������
	if (lv == maxLv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				ans = max(ans, tile[lv][i][j]);
		}
		return ans;
	}

	for (int d = 0; d < 4; d++) {
		// 2-1 ���� �����
		move(d, lv);
		// 2-2 ���� ���� �ִ밪 ���� ���ɼ��� �ִ��� �Ǻ�
		for (int c = 19; c > 0; c--)
			counter[c] += counter[c + 1] * 2;

		// lv.5���� x�� �ʰ� �ϱ� ���ؼ���
		// lv ���� x		2�� �̻� -> [x >> (5 - lv - 1)]�� [1 << (5 - lv)]�� �̻�
		if (ans == 0 || counter[ans + lv - maxLv + 1] >= (1 << (maxLv - lv)))
			ans = max(ans, dfs(lv + 1));
	}
	return ans;
}

// d �������� ������
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
				// 1. ���� �� ��ġ��
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
����� �ִ� �ִ밪 : 1048576 -> 2 ^ 20

5�Ͽ��� 13 �϶�

13���� ū ���� ����� ���ؼ���
4�Ͽ� 13�� 2�� �̻� �־�� �Ѵ�.
3�Ͽ� 12�� 4�� �̻� || (12 * 2) + 13
2�Ͽ� 11�� 8�� �̻�
1�Ͽ� 10�� 16�� �̻� ���� �ؾ� �Ѵ�.


*/