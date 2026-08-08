/// 6376e

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.precision(9);
	cout << "n e\n";
	cout << "- -----------\n";
	double e = 0;
	int n = 0, i = 1;
	e += (1 / i);
	cout << n << " " << e << "\n";
	for (n = 1; n < 10; n++) {
		i *= n;
		e += ((double)1 / i);
		cout << n << " " << e << "\n";
		if (n > 1)	cout << fixed;
	}

}