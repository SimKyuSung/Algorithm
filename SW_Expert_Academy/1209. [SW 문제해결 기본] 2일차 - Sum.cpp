/// 1209. [S/W 문제해결 기본] 2일차 - Sum 

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int a[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//ifstream cin("input.txt");
	int testCase = 10;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		n = 100;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		int d1 = 0, d2 = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int low = 0, col = 0;
			for (int j = 0; j < n; j++) {
				low += a[i][j];
				col += a[j][i];
			}
			ans = max(ans, low);
			ans = max(ans, col);
			d1 += a[i][i];
			d2 += a[i][n - i - 1];
		}
		ans = max(ans, d1);
		ans = max(ans, d2);

		cout << '#' << t << ' ' << ans << '\n';
	}
}