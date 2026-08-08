/// 14594.동방 프로젝트 (Small)

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

struct Range {
	int x, y;
};

bool operator < (Range u, Range v) {
	if (u.x == v.x)
		return u.y < v.y;
	return u.x < v.x;
}

vector <Range> query;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;	cin >> n >> m;

	query.resize(m);
	for (auto &q : query)
		cin >> q.x >> q.y;

	sort(query.begin(), query.end());

	int ans = 0, right = 0;
	for (auto q : query) {
		if (right < q.x)
			ans += (q.x - right);
		right = max(right, q.y);
	}
	ans += (n - right);
	cout << ans << endl;
}