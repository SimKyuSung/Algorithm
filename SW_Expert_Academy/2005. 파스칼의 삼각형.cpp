/// 2005. ÆÄ½ºÄ®ÀÇ »ï°¢Çü

#include <iostream>

using namespace std;

int p[11][11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	for (int i = 0; i < 11; i++) {
		p[i][0] = 1;
		for (int j = 1; j <= i; j++)
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
	}

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;

		cout << '#' << t << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++)
				cout << p[i][j] << ' ';
			cout << '\n';
		}
	}
}