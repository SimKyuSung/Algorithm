/// 1284. 수도 요금 경쟁

#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int p, q, r, s, w, a, b;
		cin >> p >> q >> r >> s >> w;
		a = p * w;
		b = q + (r < w) * (w - r) * s;
		cout << '#' << t << ' ' << ((a < b)? a : b) << '\n';
	}
}