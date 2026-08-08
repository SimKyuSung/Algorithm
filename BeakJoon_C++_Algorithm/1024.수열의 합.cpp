/// 1024.수열의 합

#include <iostream>

#define endl '\n'

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, l;
	cin >> n >> l;
	n <<= 1;
	for (int x = l; x <= 100; x++) {
		if (n % x == 0) {
			if ((n / x + 1 - x) % 2 == 0) {
				ll a = (n / x + 1 - x) / 2;
				if (a < 0)
					continue;
				for (int i = 0; i < x; i++)
					cout << a + i << ' ';
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}


/*

n = sigma(a + i) i = 0 : x - 1
  = x * (2a + x - 1) / 2

2n / x = 2a + x - 1
(2n / x + 1 - x) / 2 = a
  l <= x <= 100
 

*/