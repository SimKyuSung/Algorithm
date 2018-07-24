/// 1491. ������ �� �ٹ̱�

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		size_t n, a, b, ans = (size_t)-1 >> 1;
		cin >> n >> a >> b;
		for (int r = 1; r <= n; r++)
			for (int c = 1; c <= r && c * r <= n; c++)
				ans = min(ans, a * (r - c) + b * (n - r * c));
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*
���	n, a, b
����	r, c
�ּҰ�	a*|r-c| + b*(n-r*c)
���� ���� r * c <= n
*/