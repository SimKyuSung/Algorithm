/// 1167Ʈ���� ����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <pair<int, int> > > edge;
vector <bool> c;

int tmp = 0, ans = 0;
void dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v;
	cin >> v;
	edge.resize(v + 1);

	for (int i = 0; i < v; i++) {
		int node1, node2, w;
		cin >> node1;
		while (1) {
			cin >> node2;
			if (node2 == -1) break;
			cin >> w;
			edge[node1].push_back({ node2, w });
			edge[node2].push_back({ node1, w });
		}
	}
	// ��Ʈ�� 1�� �����ϰ� ���� �� ����� �ε����� ������
	c = vector <bool>(v + 1, 0);
	dfs(1, 0);
	
	// ���� �� �ε����� ��Ʈ�� ���� �ٽ� �˻�
	c = vector <bool>(v + 1, 0);
	dfs(tmp, 0);
	cout << ans << '\n';
}

void dfs(int x, int w) {
	c[x] = true;
	for (auto nx : edge[x]) {
		if (!c[nx.first])
			dfs(nx.first, nx.second + w);
	}
	if (ans < w) {
		ans = w;
		tmp = x;
	}
}
