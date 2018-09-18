/// 14585.»ç¼öºóÅÁ

#include<iostream>

using namespace std;

int a[302][302];
int c[302][302];

int main() {
	int i, j, k;
	int n, m;
	int x, y;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		a[x + 1][y + 1] = 1;
	}
	for (i = 1; i <= 301; i++) {
		for (j = 1; j <= 301; j++) {
			if (c[i][j - 1] > c[i - 1][j])
				c[i][j] = c[i][j - 1];
			else
				c[i][j] = c[i - 1][j];
			c[i][j] += a[i][j] * (m - i - j + 2);
		}
	}
	cout << c[301][301] << endl;
}