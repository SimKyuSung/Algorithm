/// 14489ġŲ �� ���� (...)

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	a += b;
	c *= 2;
	cout << ((a < c) ? a : (a - c)) << endl;
}