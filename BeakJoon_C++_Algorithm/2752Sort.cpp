#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
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
	if (a > b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	printf("%d %d %d\n", a, b, c);
}