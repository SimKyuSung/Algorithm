/// 15953.ป๓ฑÝ วๅลอ
/// Aน๘ - ป๓ฑÝ วๅลอ

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		int ans = 0;
		if (a) {
			int i = 1, j = 1;
			while (i < a) {
				j++;
				i += j;
			}
			if (j == 1) ans += 500;
			else if (j == 2) ans += 300;
			else if (j == 3) ans += 200;
			else if (j == 4) ans += 50;
			else if (j == 5) ans += 30;
			else if (j == 6) ans += 10;
		}
		if (b) {
			int i = 1, j = 1;
			int money = 512;
			while (i < b) {
				j <<= 1;
				i += j;
				money >>= 1;
			}
			if (i < 32)
				ans += money;
		}
		ans *= 10000;
		cout << ans << endl;
	}
}

/*

1	500
3	300
6	200
10	50
15	30
21	10

1	512
3	256
7	128
15	64
31	32


*/