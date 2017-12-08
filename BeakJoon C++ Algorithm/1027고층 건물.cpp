/// 1027고층 건물

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <size_t> b;
vector <int> counter;

int ccw(size_t, size_t, size_t, size_t, size_t, size_t);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	b.resize(n);
	counter.resize(n, 0);
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// 오른쪽 검색
		size_t x = i, y = 0;
		for (int j = i + 1; j < n; j++) {
			if (ccw(j, b[j], i, b[i], x, y) == 1) {
				x = j;
				y = b[j];
				counter[i]++;
				counter[j]++;
			}
		}		x = i, y = 0;
		ans = max(ans, counter[i]);
		cout << counter[i] << " ";
	}
	cout << endl;
	cout << ans;
}

int ccw(size_t x1, size_t y1, size_t x2, size_t y2, size_t x3, size_t y3) {
	size_t tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	size_t tmp2 = x1 * y3 + x2 * y1 + x3 * y2;
	if (tmp1 < tmp2)		return -1;
	else if (tmp1 > tmp2)	return 1;
	else					return 0;
}