/// 14503�κ� û�ұ�!

#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > room;

// 0  1  2  3
// �� �� �� ��
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
/*
���� ���� ���� ���� ���� �ݽð� ����
�� : ��, ��, ��, ��		0 : 0 1 2 3
�� : ��, ��, ��, ��		1 : 3 0 1 2
�� : ��, ��, ��, ��		2 : 2 3 0 1
�� : ��, ��, ��, ��		3 : 1 2 3 0     0 - 3 + 4
*/

//			  0  1  2  3
//            3  2  1  0
int tx[4] = { -1, 0, 1, 0 };
int ty[4] = { 0, 1, 0, -1 };

int counter = 2;

int clean(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int n, m, r, c, d, tmp;
	cin >> n >> m >> r >> c >> d;
	room.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];
	cout << clean(r, c, d) << endl;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << room[i][j] << "\t";
		cout << endl;
	}
}

int clean(int y, int x, int d) {
	// xx, yy Ž���� ����
	cout << y << " " << x << " " << d << endl;
	int ret = (room[y][x] == 0 ? 1 : 0);
	if (room[y][x] == 0) room[y][x] = counter++;
	for (int i = 0; i < 4; i++) {
		int set = (i - d + 4) % 4;
		int xx = x + tx[set];
		int yy = y + ty[set];
		if (room[yy][xx] == 0)
			return clean(yy, xx, 3 - set) + ret;
	}
	if (room[y - dy[d]][x - dx[d]] == 1)	return ret;
	else									return clean(y - dy[d], x - dx[d], d) + ret;;
}