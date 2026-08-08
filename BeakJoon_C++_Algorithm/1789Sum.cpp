#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	unsigned long long s;
	unsigned int n = 0;
	cin >> s;
	n = (-1 + sqrt(1 + 8 * s)) / 2;
	cout << n << endl;
}