/// 2814. 최장 경로

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector <bool> nodeCheck;
vector < vector <int> > edge;

int dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, x, y;
		nodeCheck.clear();
		edge.clear();

		cin >> n >> m;
		nodeCheck.resize(n, 0);
		edge.resize(n, vector<int>());
		while (m--) {
			cin >> x >> y;
			edge[x - 1].push_back(y - 1);
			edge[y - 1].push_back(x - 1);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			nodeCheck[i] = 1;
			ans = max(ans, dfs(i));
			nodeCheck[i] = 0;
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}

int dfs(int node) {
	int ret = 0;
	for (int i = 0; i < edge[node].size(); i++) {
		int nextNode = edge[node][i];
		if (!nodeCheck[nextNode]) {
			nodeCheck[nextNode] = 1;
			ret = max(ret, dfs(nextNode));
			nodeCheck[nextNode] = 0;
		}
	}
	return ret + 1;
}