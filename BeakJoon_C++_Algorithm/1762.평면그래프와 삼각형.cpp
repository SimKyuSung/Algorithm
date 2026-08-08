/// 1762.평면그래프와 삼각형

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector <int> edge[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		edge[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto j : edge[i]) {
			int y = i, x = j;
			if (edge[i].size() < edge[j].size()) swap(y, x);
			for (auto k : edge[x])
				ans += binary_search(edge[y].begin(), edge[y].end(), k);
		}
	}
	cout << ans << endl;
}