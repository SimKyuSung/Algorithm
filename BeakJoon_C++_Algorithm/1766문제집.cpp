/// 1766¹®Á¦Áý

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector <vector <int> > edge;
vector <int> ch;
priority_queue <int, vector<int>, greater<int> > pq;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	edge.resize(n);
	ch.resize(n, 0);
	while (m--) {
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		ch[b - 1]--;
	}

	for (int i = 0; i < n; i++)
		if (ch[i] == 0)
			pq.push(i);

	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		cout << t + 1 << " ";
		for (int next : edge[t]) {
			ch[next]++;
			if (ch[next] == 0)
				pq.push(next);
		}
	}
}