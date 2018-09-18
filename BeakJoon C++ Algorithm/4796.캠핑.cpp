/// 4796.д╥гн

#include <iostream>

#define MIN(a, b) (a)<(b)?(a):(b)
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	while (++t) {
		int l, p, v;
		cin >> l >> p >> v;
		if (v == 0)
			break;
		int ans = l * (v / p);
		ans += MIN(v % p, l);
		cout << "Case " << t << ": " << ans << endl;
	}
}

/*

5(8) + 5(8) + 5(8) + 

11111 00011 11100 01111

*/