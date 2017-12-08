/// 5567°áÈ¥½Ä

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <int> > edge;
vector <bool> ch;
queue < pair <int, int> > q;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	edge.resize(n);
	ch.resize(n, true);
	while (m--) {
		int a, b;	cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}
	
	int counter = 0;
	q.push({ 0, 0 });
	ch[0] = false;
	while (!q.empty()) {
		int node = q.front().first;
		int depth = q.front().second;
		if (depth < 2) {
			for (int i = 0; i < edge[node].size(); i++) {
				if (ch[edge[node][i]]) {
					q.push({ edge[node][i], depth + 1 });
					ch[edge[node][i]] = false;
					counter++;
				}
			}
		}
		q.pop();
	}
	cout << counter;
}