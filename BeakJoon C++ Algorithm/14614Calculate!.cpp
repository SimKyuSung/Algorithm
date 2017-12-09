/// 14614Calculate!

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	string c;
	cin >> a >> b >> c;
	if (c.back() % 2) a ^= b;
	cout << a << endl;
}

/*
'0' = 48
'1' = 49

b			= b
b ^ b		= 0
b ^ b ^ b	= b
*/