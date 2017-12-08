/// 14496그대 그머가 되어

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int> > edge;
vector <bool> check;

int main()
{
	int a, b, n, m;
	cin >> a >> b >> n >> m;

	edge.resize(n + 1);
	check.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		int s1, s2;
		cin >> s1 >> s2;
		edge[s1].push_back(s2);
		edge[s2].push_back(s1);
	}
	if (a == b) {
		cout << 0 << endl;
		return 0;
	}
	queue <pair <int, int> > q;
	q.push({ a, 1 });
	check[a] = false;
	while (!q.empty()) {
		a = q.front().first;
		for (int i = 0; i < edge[a].size(); i++) {
			if (edge[a][i] == b) {
				cout << q.front().second << endl;
				return 0;
			}
			if (!check[edge[a][i]]) {
				q.push({ edge[a][i], q.front().second + 1});
				check[edge[a][i]] = true;
			}
		}
		q.pop();
	}
	cout << -1 << endl;
}