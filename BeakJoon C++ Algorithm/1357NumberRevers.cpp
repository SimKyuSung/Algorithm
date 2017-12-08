// 1357NumberRevers

#include <iostream>
#include <cstdio>

using namespace std;

int intRevers(int x) {
	int ref = x % 10;
	x = x / 10;
	while (x > 0) {
		ref *= 10;
		ref += x % 10;
		x = x / 10;
	}
	return ref;
}

int main()
{
	int x, y, ans;
	cin >> x >> y;
	ans = intRevers(x) + intRevers(y);
	cout << intRevers(ans) << "\n";
}