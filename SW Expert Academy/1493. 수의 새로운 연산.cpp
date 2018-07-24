/// 1493. 수의 새로운 연산

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int p, q;
		cin >> p >> q;
		
		int x = 1, y = 1, z = 1, w = 1;
		int line = 1;
		
		while (line + y <= p) {
			line += y;
			y++;
		}
		while (line < p) {
			y--;
			x++;
			line++;
		}

		line = 1;
		while (line + w <= q) {
			line += w;
			w++;
		}
		while (line < q) {
			w--;
			z++;
			line++;
		}
		x += z;
		y += w;

		line = x + y;
		int ans = 1;
		for (int i = 0; i < line; i++)
			ans += i;
		ans -= y;

		//cout << '#' << t << ' ' << x << ' ' << y  << '\n';
		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*

수열의 합 공식을 더 빨리 구하는 방법이 있는데 수가 작으니까 그냥 하자.

*/