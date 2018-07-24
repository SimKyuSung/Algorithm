/// 4053. 전국민 건강 프로젝트

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector <ll> p(100000);
vector <short> d(100000);
vector <int> ans(1000);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int tc = 1; tc <= testCase; tc++) {
		int n, q;
		ll t;

		cin >> n >> t >> q;

		// 2 동쪽(+1), 4서쪽(-1)
		for (int i = 0; i < n; i++)
			cin >> p[i] >> d[i];
		for (int i = 0; i < q; i++)
			cin >> ans[i];

		// 1. 처음부터 왼쪽으로 가는 애들정리
		int l = 0, r = 0;
		while (r < n && d[r] != 1)
			r++;
		while (l < r)
			p[l++] -= t;

		while (r < n) {
			ll x;
			while (r < n && d[r] != 2)
				r++;
			if (r != n) {
				if (d[r - 1] != 2)
					x = (p[r - 1] + p[r]) / 2;
				else
					x = p[r - 1];
				p[r] -= min(t, p[r] - x);
				while (l < r) {
					p[l] += min(t, x - p[l]);
					l++;
				}
			}
			else {
				while (l < r)
					p[l++] += t;
			}
			l++;
			r++;
		}

		cout << '#' << tc;
		for (int i = 0; i < q; i++)
			cout << ' ' << p[ans[i] - 1];
		cout << '\n';
	}
}