/// 11724연결 요소의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// edge, check
vector <vector <int> > e;
vector <bool> c;

queue <int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, u, v, ans = 0;
	cin >> n >> m;
	e.resize(n + 1);
	c.resize(n + 1, false);
	while (m--) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!c[i]) {
			ans++;
			q.push(i);
			c[i] = true;
			while (!q.empty()) {
				int p = q.front();
				q.pop();
				for (auto node : e[p]) {
					if (!c[node]) {
						c[node] = true;
						q.push(node);
					}
				}
			}
		}
	}
	cout << ans << endl;
}