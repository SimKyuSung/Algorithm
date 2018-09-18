/// 15654.N°ú M (5)

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

bool check[8];
int n, m, ans[8];
vector <int> a;
void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
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
		if (!check[i]) {
			ans[x] = a[i];
			check[i] = 1;
			dfs(x + 1);
			check[i] = 0;
		}
	}
}