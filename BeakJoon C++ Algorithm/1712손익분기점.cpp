/// 1712손익분기점

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	size_t a, b, c;
	cin >> a >> b >> c;
	if (a + b < c) {
		cout << 1;
		return 0;
	}
	if (b > c) {
		cout << -1;
		return 0;
	}
	cout << a / (c - b) + 1;
	return 0;
}

/*

cx - bx - a > 0

x (c - b) > a
x > a / (c - b)

*/