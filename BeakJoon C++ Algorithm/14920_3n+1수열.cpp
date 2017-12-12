/// 14920_3n+1¼ö¿­

#include <iostream>

using namespace std;

int main()
{
	int c1, n = 1;
	cin >> c1;
	while (c1 != 1) {
		if (c1 % 2) c1 = c1 * 3 + 1;
		else		c1 /= 2;
		n++;
	}
	cout << n << endl;
}