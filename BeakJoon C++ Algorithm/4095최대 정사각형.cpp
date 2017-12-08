/// 4095최대 정사각형

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > a(1000, vector<int> (1000));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0) break;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j]) ans = 1;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				a[i][j] += min(a[i - 1][j - 1], min(a[i - 1][j], a[i][j - 1])) * a[i][j];
				ans = max(ans, a[i][j]);
			}
		}
		cout << ans << "\n";
	}
}

