/// 15663.N°ú M (9)

#include <iostream>
#include <vector>
#include <map>

#define endl '\n'

using namespace std;

int n, m, ans[8], input;
map <int, int> a;

void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a[input]++;
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
	map<int, int>::iterator iter;
	for (iter = a.begin(); iter != a.end(); iter++) {
		if (iter->second) {
			iter->second--;
			ans[x] = iter->first;
			dfs(x + 1);
			iter->second++;
		}
	}
}