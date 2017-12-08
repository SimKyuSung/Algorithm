/// 2573����

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector < vector <int> > ice;
vector <vector <int> > dissolve;
vector <vector < bool> > ch;
queue < pair <int, int> > q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ice.resize(n, vector <int>(m, 0));
	dissolve.resize(n, vector <int>(m, 0));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];
	
	// 1. 1�̻� ���� ���� ����
	int iceCounter = -1;
	int year = 0;
	while (iceCounter) {

		// 2. üũ �迭 �ʱ�ȭ
		ch.clear();
		ch.resize(n, vector <bool>(m, false));
		
		// 3. ���� ������ bfs �˻��Ͽ� ���Ͽ� ���� ����
		iceCounter = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!ch[i][j] && 0 <ice[i][j]) {
					iceCounter++;
					q.push({ i, j });
					ch[i][j] = true;
					while (!q.empty()) {
						int x = q.front().second;
						int y = q.front().first;
						q.pop();
						for (int d = 0; d < 4; d++) {
							int xx = x + dx[d];
							int yy = y + dy[d];
							if (!ch[yy][xx] && 0 < ice[yy][xx]) {
								q.push({ yy, xx });
								ch[yy][xx] = true;
							}
						}
					}
				}
			}
		}

		// 4. ���Ͽ��� 2�� �̻��̶�� ���� 
		if (iceCounter > 1) {
			cout << year;
			return 0;
		}

		// 5. ���� ���̱�
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				dissolve[i][j] = 0;
				for (int d = 0; d < 4; d++) {
					int xx = j + dx[d];
					int yy = i + dy[d];
					if (ice[yy][xx] < 1) dissolve[i][j]--;
				}
			}
		}
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				ice[i][j] += dissolve[i][j];
		year++;
		
	}
	cout << 0;
}

/*

�ִ� ����� �귯�� ��� ������ ������? �׳� ���Ͽ��� �������� ��� ���� ������...
300 300
0  0  0  0  0  0 ...
0  10 10 10 10 10
0  10 10 10 10 10
...
0  10 10 10 10 10
0  10 10 10 10 10
0  0  0  0  0  0 ...


*/