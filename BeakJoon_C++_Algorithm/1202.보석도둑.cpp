/// 1202.보석도둑

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

vector <pair<int, int> > j;
vector <int> c;
priority_queue <int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	size_t ans = 0;
	cin >> n >> k;
	j.resize(n);
	c.resize(k);

	for (int i = 0; i < n; i++)
		cin >> j[i].first >> j[i].second;
	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(j.begin(), j.end());
	sort(c.begin(), c.end());

	int index = 0;
	for (int i = 0; i < k; i++) {
		while (index < n && j[index].first <= c[i])
			pq.push(j[index++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
}

/*

1. 비싼 물건 부터
2. 가벼운 물건 부터 적제



*/