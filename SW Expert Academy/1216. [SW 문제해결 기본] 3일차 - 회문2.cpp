/// 1216. [S/W 문제해결 기본] 3일차 - 회문2

#include <iostream>
#include <fstream>
using namespace std;

char b[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("input.txt");

	int testCase = 10;
	for (int t = 1; t <= testCase; t++) {
		int x;
		cin >> x;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> b[i][j];

		int ans = 0;
		for (int n = 100; n > 1; n--) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100 - n + 1; j++) {
					bool x1 = 1, x2 = 1;
					for (int k = 0; k < n / 2; k++) {
						// low
						if (b[i][j + k] != b[i][j + n - k - 1])
							x1 = 0;
						// col
						if (b[j + k][i] != b[j + n - k - 1][i])
							x2 = 0;
					}
					if (x1 || x2) {
						ans = n;
						break;
					}
				}
				if (ans)
					break;
			}
			if (ans)
				break;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}