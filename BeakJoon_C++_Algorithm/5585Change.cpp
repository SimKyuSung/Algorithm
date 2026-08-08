// 5585Change

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int m, a = 0;
	cin >> m;
	m = 1000 - m;
	a += m / 500;
	m %= 500;
	a += m / 100;
	m %= 100;
	a += m / 50;
	m %= 50;
	a += m / 10;
	m %= 10;
	a += m / 5;
	m %= 5;
	a += m;
	printf("%d\n", a);
}
