/// 1974. 스도쿠 검증

#include <iostream>
#include <memory.h>

using namespace std;

bool c1[9][9];
bool c2[9][9];
bool c3[3][3][9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));

		int s, ans = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> s;
				s--;
				if (c1[i][s] | c2[s][j] | c3[i / 3][j / 3][s])
					ans = 0;
				c1[i][s] = c2[s][j] = c3[i / 3][j / 3][s] = 1;
			}
		}
		cout << '#' << t << ' ' << ans << '\n';

	}
}