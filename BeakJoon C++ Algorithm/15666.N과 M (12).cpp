/// 15666.N°ú M (12)

#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int n, m, ans[8], input;
set <int> a;

void dfs(int, set<int, int>::iterator);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.insert(input);
	}
	set<int>::iterator iter = a.begin();
	dfs(0, iter);
}

void dfs(int x, set<int>::iterator iter) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	for (; iter != a.end(); iter++) {
		ans[x] = *iter;
		dfs(x + 1, iter);
	}
}