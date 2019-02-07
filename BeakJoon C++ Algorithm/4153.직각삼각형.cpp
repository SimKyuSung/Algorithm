/// 4153.Á÷°¢»ï°¢Çü

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && a == c && a == 0)
			break;
		if (a > b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		if (b > c) {
			b ^= c;
			c ^= b;
			b ^= c;
		}
		cout << ((a * a + b * b == c * c) ? "right" : "wrong") << endl;
	}
}