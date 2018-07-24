/// 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱

#include <iostream>

using namespace std;

int recursive(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	for (int t = 1; t <= testCase; t++) {
		
		int x, n, m;
		cin >> x >> n >> m;

		cout << '#' << t << ' ' << recursive(n, m) << '\n';
	}
}

int recursive(int n, int m) {
	if (m == 0)
		return 1;
	return n * recursive(n, m - 1);
}