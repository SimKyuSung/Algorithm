#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 100000000

using namespace std;

//int city[1001][1001];
// 그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치) 
vector<pair<int, int> > city1[1001];
vector<pair<int, int> > city2[1001];

vector<vector<int> > cash1(1001, vector<int>(1001, INF));
vector<vector<int> > cash2(1001, vector<int>(1001, INF));

void dijkstra1(int);
void dijkstra2(int);

int main()
{
	int N, M, X;
	int A, B, T;
	int ans = 0;

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> T;
		city1[A].push_back(make_pair(T, B));
		city2[B].push_back(make_pair(T, A));
	}

	// X에서 시작하는 최소 가중치
	dijkstra1(X);
	// X로 도착하는 최소 가중치
	dijkstra2(X);

	for (int i = 1; i < N + 1; i++)
		ans = max(ans, cash1[X][i] + cash2[X][i]);
	cout << ans << endl;

	return 0;
}

void dijkstra1(int src) {
	cash1[src][src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (cash1[src][here] < cost) continue;

		for (int i = 0; i < city1[here].size(); i++) {
			int nextDist = cost + city1[here][i].first;
			int there = city1[here][i].second;

			if (cash1[src][there] > nextDist) {
				cash1[src][there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}


void dijkstra2(int src) {
	cash2[src][src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (cash2[src][here] < cost) continue;

		for (int i = 0; i < city2[here].size(); i++) {
			int nextDist = cost + city2[here][i].first;
			int there = city2[here][i].second;

			if (cash2[src][there] > nextDist) {
				cash2[src][there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}