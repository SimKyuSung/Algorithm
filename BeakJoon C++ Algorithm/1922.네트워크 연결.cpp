///1922.네트워크 연결

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

struct Edge {
	int b, c;
};

bool operator < (Edge a, Edge b) {
	return a.c > b.c;
}

vector <Edge> edge[1001];

priority_queue <Edge> pq;
bool check[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;

	int starNode1, starNode2, counter = 100000;
	while (m--) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
		if (c < counter) {
			counter = c;
			starNode1 = a;
			starNode2 = b;
		}
	}

	int ans = counter;
	check[starNode1] = check[starNode2] = 1;

	for (int i = 0; i < edge[starNode1].size(); i++)
		pq.push(edge[starNode1][i]);
	for (int i = 0; i < edge[starNode2].size(); i++)
		pq.push(edge[starNode2][i]);

	counter = 2;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (!check[now.b]) {
			counter++;
			for (int i = 0; i < edge[now.b].size(); i++)
				pq.push(edge[now.b][i]);
			ans += now.c;
		}
		if (counter == n)
			break;
		check[now.b] = 1;
	}
	cout << ans << endl;

}
