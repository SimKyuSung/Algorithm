/// 15955.부스터
/// D번 - 부스터

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

struct Point {
	int d, i;
};
struct Line {
	int d, i, j;
};
struct Query {
	int a, b, hp, i;
};

vector <int> p;
int getRoot(int);
void marge(int, int);

vector <Point> sortX;
vector <Point> sortY;
vector <Query> query;

bool operator < (Point &a, Point &b) {
	return a.d < b.d;
}
bool operator < (Line t, Line u) {
	return t.d > u.d;
}
bool operator < (Query &a, Query &b) {
	return a.hp < b.hp;
}

priority_queue <Line> pq;
vector <bool> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q, a, b, hp;
	cin >> n >> q;

	sortX.resize(n);
	sortY.resize(n);
	p.resize(n);
	query.resize(q);
	ans.resize(q, 0);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sortX[i] = { x, i };
		sortY[i] = { y, i };
		p[i] = i;
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> hp;
		query[i] = { a - 1, b - 1, hp, i };
	}

	// init
	sort(sortX.begin(), sortX.end());
	sort(sortY.begin(), sortY.end());
	sort(query.begin(), query.end());
	// pq에 인접 한 점들의 거리입력
	for (int i = 1; i < n; i++) {
		pq.push({ (sortX[i].d - sortX[i - 1].d), sortX[i].i, sortX[i - 1].i });
		pq.push({ (sortY[i].d - sortY[i - 1].d), sortY[i].i, sortY[i - 1].i });
	}

	// x or y 같은 값 marge
	for (int i = 0; i < q; i++) {
		a = query[i].a;
		b = query[i].b;
		hp = query[i].hp;

		while (!pq.empty() && pq.top().d <= hp) {
			marge(pq.top().i, pq.top().j);
			pq.pop();
		}
		a = getRoot(a);
		b = getRoot(b);
		if (a == b)
			ans[query[i].i] = 1;
	}
	for (int i = 0; i < q; i++) {
		if (ans[i])	cout << "YES\n";
		else		cout << "NO\n";
	}
}

int getRoot(int a) {
	if (p[a] == a) return a;
	return p[a] = getRoot(p[a]);
}
void marge(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a != b)
		p[b] = a;
}