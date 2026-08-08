/// 15574.Ω≈»£1

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector < pair < pair<int, int>, double> > p;
vector < vector < pair < pair<int, int>, double> > > pp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	p.resize(n, { {0, 0}, 0 });
	for (int i = 0; i < n; i++)
		cin >> p[i].first.first >> p[i].first.second;

	sort(p.begin(), p.end());

	int index = -1, px = 0xf0000000;
	for (int i = 0; i < n; i++) {
		if (px < p[i].first.first) {
			pp.push_back(vector< pair < pair<int, int>, double> >(0));
			index++;
			px = p[i].first.first;
		}
		pp[index].push_back(p[i]);
	}

	for (int i = 1; i < pp.size(); i++) {
		for (int j = 0; j < pp[i].size(); j++) {
			for (int k = 0; k < pp[i - 1].size(); k++) {
				ll xx = pp[i][j].first.first - pp[i - 1][k].first.first;
				ll yy = pp[i][j].first.second - pp[i - 1][k].first.second;
				pp[i][j].second = max(pp[i][j].second, sqrt(xx * xx + yy * yy) + pp[i - 1][k].second);
			}
			//cout << pp[i][j].second << endl;
		}
	}
	double ans = 0;
	for (int i = 0; i < pp.back().size(); i++) {
		ans = max(ans, pp.back()[i].second);
	}

	cout << fixed;
	cout.precision(7);
	cout << ans << endl;
	return 0;
}

/*

5
4
3	.		.		.
2
1	.		.		.
0	1	2	3	4	5


1 1
5 3

16 + 4
32
*/