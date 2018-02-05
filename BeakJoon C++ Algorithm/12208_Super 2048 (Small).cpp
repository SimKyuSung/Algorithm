/// 12208_Super 2048 (Small)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int t, n;
string dir;

//			  u  r   d  l
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int dsx[4] = { 0, 1, 1, 0 };
int dsy[4] = { 0, 0, 1, 1 };

int indexDir[128];

int b[20][20];

void move(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ofstream outFile("output.txt");

	indexDir['u'] = 0;
	indexDir['r'] = 1;
	indexDir['d'] = 2;
	indexDir['l'] = 3;

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> dir;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> b[i][j];

		move(indexDir[dir[0]]);
		cout << "Case #" << tc << ":\n";
		outFile << "Case #" << tc << ":\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << b[i][j] << " ";
				outFile << b[i][j] << " ";
			}
			cout << '\n';
			outFile << '\n';
		}
	}
}

// d �������� ������
void move(int d) {

	int xs = dsx[d] * (n - 1);
	int ys = dsy[d] * (n - 1);
	for (int i = 0; i < n; i++) {
		// 1. ���� ���ϱ�
		int x = xs, y = ys;
		int index = x, indey = y;
		for (int j = 1; j < n; j++) {
			x += dx[d];
			y += dy[d];

			// 1-1. 0�� �ƴϸ� �ε��� ���
			if (b[y][x] != 0) {
				// 1-2. �ô� ����
				if (b[y][x] == b[indey][index]) {
					b[indey][index] <<= 1;
					b[y][x] = 0;
				}
				index = x;
				indey = y;
			}
		}

		// 2. ���� 0 ã��
		x = xs, y = ys;
		int j = 1;
		while (j < n) {
			// 2-1. 0 �̸� �ε��� ���
			if (b[y][x] == 0) {
				index = x;
				indey = y;
				break;
			}
			x += dx[d];
			y += dy[d];
			j++;
		}
		// 3. 0 ���� ���� ã��
		while (j < n) {
			// 3-1. 0�� �ƴϸ�
			x += dx[d];
			y += dy[d];
			j++;
			if (b[y][x] != 0) {
				b[indey][index] = b[y][x];
				b[y][x] = 0;
				index += dx[d];
				indey += dy[d];
			}
		}
		xs += dx[(d + 3) % 4];
		ys += dy[(d + 3) % 4];
	}
}