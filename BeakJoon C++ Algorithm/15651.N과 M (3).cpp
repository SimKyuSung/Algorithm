/// 15651.N°ú M (3)

#include <iostream>

#define endl '\n'

using namespace std;

int n, m, ans[8];
void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	dfs(0);
}

void dfs(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		ans[x] = i + 1;
		dfs(x + 1);
	}
}