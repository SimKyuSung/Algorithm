/// 15664.N°ú M (10)

#include <iostream>
#include <vector>
#include <map>

#define endl '\n'

using namespace std;

int n, m, ans[8], input;
map <int, int> a;

void dfs(int, map<int, int>::iterator);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a[input]++;
	}
	map<int, int>::iterator iter = a.begin();
	dfs(0, iter);
}

void dfs(int x, map<int, int>::iterator iter) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	for (;iter != a.end(); iter++) {
		if (iter->second) {
			iter->second--;
			ans[x] = iter->first;
			dfs(x + 1, iter);
			iter->second++;
		}
	}
}