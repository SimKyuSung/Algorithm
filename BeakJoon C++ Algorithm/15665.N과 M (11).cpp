/// 15665.N°ú M (11)

#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int n, m, ans[8], input;
set <int> a;

void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.insert(input);
	}
	dfs(0);
}

void dfs(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	for (auto a : a) {
		ans[x] = a;
		dfs(x + 1);
	}
}