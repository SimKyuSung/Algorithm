/// 2056.ÀÛ¾÷

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector <vector <int> > preTask;
vector <int> timeTask;
vector <int> check;

int dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n;
	
	preTask.resize(n);
	timeTask.resize(n);
	check.resize(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> timeTask[i] >> m;
		preTask[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> preTask[i][j];
			preTask[i][j]--;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dfs(i));
	cout << ans << endl;
}

int dfs(int x) {
	if (check[x] != -1)
		return check[x];

	int ret = 0;

	for (int i = 0; i < preTask[x].size(); i++)
		ret = max(ret, dfs(preTask[x][i]));

	return check[x] = ret + timeTask[x];
}