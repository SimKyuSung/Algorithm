/// 11779.최소비용 구하기 2

#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Bus {
	int a, b, w, counter;
	bool operator()(Bus &t, Bus &u) {
		return t.w > u.w;
	}
};
vector <vector <Bus> > edge;
vector <int> check;

priority_queue <Bus, vector <Bus>, Bus> pq;
vector <int> ans;
void dfsPrint(int);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, w;
	cin >> n >> m;

	edge.resize(n + 1, vector <Bus>());
	check.resize(n + 1, 0);
	ans.resize(n + 1);

	while (m--) {
		cin >> a >> b >> w;
		edge[a].push_back({ a, b, w, 0 });
	}
	cin >> a >> b;

	pq.push({ 0, a, 0, 1 });
	while (!pq.empty()) {
		Bus x = pq.top();
		pq.pop();
		if (x.b == b) {
			check[x.b] = 1;
			ans[x.b] = x.a;
			cout << x.w << endl;
			cout << x.counter << endl;
			break;
		}

		if (!check[x.b]) {
			check[x.b] = 1;
			ans[x.b] = x.a;
			for (int i = 0; i < edge[x.b].size(); i++) {
				Bus next = edge[x.b][i];
				next.counter = x.counter + 1;
				next.w += x.w;
				if (!check[next.b])
					pq.push(next);
			}
		}
	}
	dfsPrint(b);
	return 0;
}

void dfsPrint(int b) {
	if (b == 0)
		return;
	else {
		dfsPrint(ans[b]);
		cout << b << ' ';
	}
}


/*

1억
1,000 * 100,000 = 100,000,000

*/