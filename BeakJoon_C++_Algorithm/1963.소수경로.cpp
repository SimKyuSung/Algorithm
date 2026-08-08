/// 1963.소수경로

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

const int LIM = 10000;
bool check[LIM];
vector <int> p;
vector <vector <int> > edge(LIM);

struct Point {
	int p, counter;
};

int bfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < LIM; i++) {
		if (!check[i]) {
			if (i > 1000)
				p.push_back(i);
			for (int j = i; j < LIM; j += i)
				check[j] = 1;
		}
	}

	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			int counter = 0, tmp1 = p[i], tmp2 = p[j];
			while (tmp1) {
				counter += (tmp1 % 10 != tmp2 % 10);
				tmp1 /= 10;
				tmp2 /= 10;
			}
			if (counter == 1) {
				edge[p[i]].push_back(p[j]);
				edge[p[j]].push_back(p[i]);
			}
		}
	}

	int t, n, m, ans;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans = bfs(n, m);
		if (ans == -1)	cout << "Impossible" << endl;
		else			cout << ans << endl;
	}
}

int bfs(int x, int y) {
	memset(check, 0, sizeof(check));

	queue <Point> q;
	q.push({ x, 0 });
	check[x] = 1;

	while (!q.empty()) {
		x = q.front().p;
		int counter = q.front().counter;
		q.pop();
		//cout << x << ' ' << counter << endl;
		if (x == y)
			return counter;
		for (auto next : edge[x]) {
			if (!check[next]) {
				check[next] = 1;
				q.push({ next, counter + 1 });
			}
		}
	}
	return -1;
}