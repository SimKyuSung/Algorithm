/// 1761.정점들의 거리

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Edge {
	unsigned int node, weight;
};

vector<Edge> edge[40001];
int p[40001][17];
unsigned int w[40001];
int depth[40001];
bool check[40001];

void dfs(int, int);
int getLCA(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	unsigned int n, m, a, b, c;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	dfs(1, 0);
	depth[0] = -1;

	cin >> m;
	while (m--)	{
		cin >> a >> b;
		cout << w[a] + w[b] - w[getLCA(a, b)] * 2 << endl;
	}

}

void dfs(int x, int l) {
	check[x] = 1;
	depth[x] = l;

	for (int i = 0; i < edge[x].size(); i++) {
		Edge &next = edge[x][i];
		if (!check[next.node]) {
			int tmp = x, y = 0;
			p[next.node][0] = x;
			w[next.node] = w[x] + next.weight;
			while (p[tmp][y] != 0) {
				p[next.node][y + 1] = p[tmp][y];
				tmp = p[tmp][y];
				y++;
			}
			dfs(next.node, l + 1);
		}
	}
}

int getLCA(int a, int b) {
	if (a == b)
		return a;
	if (depth[a] < depth[b]) {
		a ^= b;
		b ^= a;
		a ^= b;
	}

	unsigned int ret = 0;
	// 높이 맞추기
	while (depth[a] != depth[b]) {
		int i = 16;
		while (depth[p[a][i]] < depth[b])
			i--;
		a = p[a][i];
	}

	// LCA 찾기
	while (a != b) {
		int i = 16;
		while (i > 0 && p[a][i] == p[b][i])
			i--;
		a = p[a][i];
		b = p[b][i];
	}
	return a;
}
/*

7
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
3
1 6
1 4
2 6

*/