/// 1647.도시 분할 계획

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Edge {
	int a, b, c;
};

bool operator < (Edge u, Edge v) {
	return u.c < v.c;
}

vector <Edge> edge;
vector <int> p;

int getRoot(int);
bool marge(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	p.resize(n);
	edge.resize(m);
	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++)
		cin >> edge[i].a >> edge[i].b >> edge[i].c;
	sort(edge.begin(), edge.end());

	int ans = 0, counter = 0;
	for (int i = 0; i < m; i++) {
		if (marge(edge[i].a, edge[i].b)) {
			ans += edge[i].c;
			counter++;
			if (counter == n - 2)
				break;
		}
	}
	cout << ans << endl;
}

int getRoot(int a) {
	if (p[a] == a)	return a;
	return p[a] = getRoot(p[a]);
}
bool marge(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a != b) {
		p[b] = a;
		return 1;
	}
	return 0;
}