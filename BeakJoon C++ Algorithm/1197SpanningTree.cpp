#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, w;
int n1, n2;

// graph �Է� edge[here] = pair(w, there)
vector<pair<int, int> > edge[10001];
// visited ǥ��
vector<bool> visited(10001, false);

int Prim(int);

int main() {
	// �Է� ������
	// node ����, edge ����
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		// edge �Է�
		cin >> n1 >> n2 >> w;
		// vector ����
		edge[n1].push_back({ w, n2 });
		edge[n2].push_back({ w, n1 });
	}

	cout << Prim(1) << endl;
}

int Prim(int start) {
	// �������� �켱���� ť ����
	int ans = 0;
	priority_queue<pair<int, int> > pq;

	// ���� ���� start, (-w, there)
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		// �������� queue�� ����������, -1�� ���ؼ� cost�� ���
		int cost = -pq.top().first;
		int there = pq.top().second;
		pq.pop();
		// �̹� �湮�� node ��� pass
		if (visited[there]) continue;
		// ������ ǥ��
		visited[there] = true;
		// ������ ���
		ans += cost;
		// �űԷ� ����� node�� edge�� push 
		for (int i = 0; i < edge[there].size(); i++)
			pq.push({ -edge[there][i].first, edge[there][i].second });
	}
	return ans;
}