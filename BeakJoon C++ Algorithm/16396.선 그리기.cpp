/// 16396.선 그리기

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

struct Line {
	int x, y;
};

bool cmp(Line v, Line u) {
	return v.x != u.x ? v.x < u.x : v.y < u.y;
}
vector <Line> line;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	line.resize(n);

	int ans = 0, x, y;
	for (int i = 0; i < n; i++)
		cin >> line[i].x >> line[i].y;

	sort(line.begin(), line.end(), cmp);

	x = line[0].x, y = line[0].y;
	for (int i = 1; i < n; i++) {
		if (line[i].x <= y)
			y = max(y, line[i].y);
		else {
			ans += y - x;
			x = line[i].x;
			y = line[i].y;
		}
	}
	ans += y - x;
	cout << ans << endl;
}