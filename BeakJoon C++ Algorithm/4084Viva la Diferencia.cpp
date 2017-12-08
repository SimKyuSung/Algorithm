/// 4084Viva la Diferencia

#include <iostream>
#include <cmath>

using namespace std;

int a, b, c, d;
int aa, bb, cc, dd;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		int ans = 0;
		while (a != b || a != c || a != d) {
			ans++;
			aa = abs(a - b);
			bb = abs(b - c);
			cc = abs(c - d);
			dd = abs(d - a);
			a = aa;
			b = bb;
			c = cc;
			d = dd;
		}
		cout << ans << "\n";

	}

}