/// 2644ÃÌ¼ö°è»ê

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <vector <int> > edge;
vector <bool> ch
;
int solve(int, int);

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	int a, b;
	cin >> n >> a >> b >> m;
	edge.resize(n);
	ch.resize(n, true);
	for (int i = 0; i < m; i++) {
		int tmpA, tmpB;
		cin >> tmpA >> tmpB;
		edge[tmpA - 1].push_back(tmpB - 1);
		edge[tmpB - 1].push_back(tmpA - 1);
	}
	cout << solve(a - 1, b - 1) << endl;
}

int solve(int a, int b) {
	queue <pair <int, int> > q;
	q.push({ a, 0 });
	ch[a] = true;
	while (!q.empty()) {
		int pNode = q.front().first;
		int depth = q.front().second;
		for (int i = 0; i < edge[pNode].size(); i++) {
			int cNode = edge[pNode][i];
			if (cNode == b)
				return depth + 1;
			if (ch[cNode]) {
				q.push({ cNode, depth + 1 });
				ch[cNode] = false;
			}
		}
		q.pop();
	}
	return -1;
}


/*


*/