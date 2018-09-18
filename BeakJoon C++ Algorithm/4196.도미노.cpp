/// 4196.µµ¹Ì³ë

#include <iostream>
#include <memory.h>
#include <vector>

#define endl '\n'

using namespace std;

vector <vector <int> > edge;
bool check[100001];
bool root[100001];

bool dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;	cin >> t;
	while (t--) {
		int n, m, x, y, ans  = 0;
		memset(check, 0, sizeof(check));
		memset(root, 0, sizeof(root));
		edge.clear();

		cin >> n >> m;
		edge.resize(n);
		while (m--) {
			cin >> x >> y;
			edge[x - 1].push_back(y - 1);
		}
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				ans++;
				check[i] = 1;
				ans -= dfs(i);
				root[i] = 1;
			}
		}
		cout << ans << endl;
	}
}

bool dfs(int n) {
	bool ret = 0;
	for (int i = 0; i < edge[n].size(); i++) {
		int x = edge[n][i];
		if (root[x]) {
			root[x] = 0;
			ret = 1;
		}
		if (!check[x]) {
			check[x] = 1;
			ret |= dfs(x);
		}
	}
	return ret;
}