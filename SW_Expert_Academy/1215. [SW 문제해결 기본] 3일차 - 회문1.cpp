/// 1215. [S/W 문제해결 기본] 3일차 - 회문1

#include <iostream>

using namespace std;

char b[8][8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	for (int t = 1; t <= testCase; t++) {
		int n, counter = 0;
		cin >> n;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> b[i][j];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - n + 1; j++) {
				bool x1 = 1, x2 = 1;
				for (int k = 0; k < n / 2; k++) {
					// low
					if (b[i][j + k] != b[i][j + n - k - 1])
						x1 = 0;
					// col
					if (b[j + k][i] != b[j + n - k - 1][i])
						x2 = 0;
				}
				counter += x1 + x2;
			}
		}

		cout << '#' << t << ' ' << counter << '\n';
	}
}