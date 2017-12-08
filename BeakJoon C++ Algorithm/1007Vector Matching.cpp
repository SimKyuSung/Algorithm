/// 1007Vector Matching

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;

vector <int> x(n);
vector <int> y(n);

size_t ans;
int xs, ys;
void vectorMatching(int, int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout.precision(6);
	cout << fixed;

	cin >> t;
	while (t--) {
		cin >> n;
		x = vector <int>(n);
		y = vector <int>(n);
		xs = 0;
		ys = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			xs += x[i];
			ys += y[i];
		}
		ans = 0xffffffffffffffff;
		vectorMatching(0, 0, 0, 0);

		cout << sqrt(ans) << "\n";

	}
}
void vectorMatching(int index, int xx, int yy, int counter) {
	if (counter == n / 2) {
			ans = min(ans, size_t(xs - xx - xx) * (xs - xx - xx) + size_t(ys - yy - yy) * (ys - yy - yy));
		return;
	}
	// 생성 할수 있는 백터맨이 없으면 종료
	if (n / 2 - index + counter < 0)	return;
	vectorMatching(index + 1, xx + x[index], yy + y[index], counter + 1);
	vectorMatching(index + 1, xx, yy, counter);
}

/*

각 포인트는 (0, 0)으로 부터 벡터와 같다 

2
4
5 5
5 -5
-5 5
-5 -5
2
-100000 -100000
100000 100000

ab = b - a

a + b + c + d
ab + cd + ef = b - a + d - c + f - e


*/