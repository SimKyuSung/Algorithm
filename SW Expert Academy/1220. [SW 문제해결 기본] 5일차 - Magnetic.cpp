/// 1220. [S/W �����ذ� �⺻] 5���� - Magnetic

#include <iostream>

using namespace std;

// n = 1 �Ʒ��� ������, s = 2 ���ο�����
int table[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;

	for (int t = 1; t <= testCase; t++) {
		int n, counter = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> table[i][j];

		for (int j = 0; j < n; j++) {
			bool x = 0;
			for (int i = 0; i < n; i++) {
				if (table[i][j] == 1)
					x = 1;
				if (x && table[i][j] == 2) {
					counter++;
					x = 0;
				}
			}
		}

		cout << '#' << t << ' ' << counter << '\n';
	}
}