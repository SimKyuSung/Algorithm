#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, w;
int n1, n2;

// graph 입력 edge[here] = pair(w, there)
vector<pair<int, int> > edge[10001];
// visited 표기
vector<bool> visited(10001, false);

int Prim(int);

int main() {
	// 입력 시퀸스
	// node 개수, edge 개수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		// edge 입력
		cin >> n1 >> n2 >> w;
		// vector 삽입
		edge[n1].push_back({ w, n2 });
		edge[n2].push_back({ w, n1 });
	}

	cout << Prim(1) << endl;
}

int Prim(int start) {
	// 내림차순 우선순위 큐 생성
	int ans = 0;
	priority_queue<pair<int, int> > pq;

	// 시작 노드는 start, (-w, there)
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		// 음수값을 queue에 삽입함으로, -1을 곱해서 cost값 출력
		int cost = -pq.top().first;
		int there = pq.top().second;
		pq.pop();
		// 이미 방문한 node 라면 pass
		if (visited[there]) continue;
		// 지나감 표시
		visited[there] = true;
		// 누적값 계산
		ans += cost;
		// 신규로 연결된 node의 edge를 push 
		for (int i = 0; i < edge[there].size(); i++)
			pq.push({ -edge[there][i].first, edge[there][i].second });
	}
	return ans;
}