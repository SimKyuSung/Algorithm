/// 8983.사냥꾼

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

struct Range {
	int left, right;
};


bool operator< (Range &a, Range &b) {
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}

vector <int> s;
vector <Range> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m, n, l, x, y;
	cin >> m >> n >> l;
	s.resize(m);
	for (auto &x : s)
		cin >> x;

	while (n--) {
		cin >> x >> y;
		y -= l;
		if (y <= 0)
			a.push_back({ x + y, x - y });
	}
	n = a.size();

	sort(s.begin(), s.end());
	sort(a.begin(), a.end());

	int i = 0, ans = 0;
	for (auto x : s) {
		while (i < n && a[i].left <= x) {
			ans += (x <= a[i].right);
			i++;
		}
	}
	cout << ans << endl;
}

/*
끝없는 사냥을 시작하지!

머리에 한방!

*/