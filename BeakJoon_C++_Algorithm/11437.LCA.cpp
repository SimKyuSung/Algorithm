/// 11437.LCA

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <vector <int> > edge;

int p[50001][17];
int depth[50001];
bool check[50001];

void dfs(int, int);
int getLCA(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;
	cin >> n;

	edge.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j < 10; j++)
	//		cout << p[i][j] << ' ';
	//	cout << endl;
	//}
	
	depth[0] = -1;

	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << getLCA(a, b) << endl;
	}
}

void dfs(int x, int level) {
	check[x] = 1;
	depth[x] = level;
	for (int i = 0; i < edge[x].size(); i++) {
		int next = edge[x][i];
		if (!check[next]) {
			int tmp = x, y = 0;
			p[next][0] = x;
			while (p[tmp][y] != 0) {
				p[next][y + 1] = p[tmp][y];
				tmp = p[tmp][y];
				y++;
			}

			dfs(next, level + 1);
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

	// 높이 맞추기
	while (depth[a] != depth[b]) {
		//cout << a << endl;
		int i = 16;
		while (depth[p[a][i]] < depth[b])
			i--;
		a = p[a][i];
		//cout << a << endl;
	}

	// 같은 높이의 공통 부모노드 찾기
	while (a != b) {
		//cout << a << ' ' << b << endl;
		int i = 16;
		while (i > 0 && p[a][i] == p[b][i]) {
			i--;
		}
		a = p[a][i];
		b = p[b][i];
	}

	return a;
}

