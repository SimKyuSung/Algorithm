#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int, int);

int main()
{
	ios::sync_with_stdio(false);
	int a, b, tmpGCD, tmpLCM;
	cin >> a >> b;
	tmpGCD = gcd(a, b);
	tmpLCM = b / tmpGCD * a;
	printf("%d\n%d\n", tmpGCD, tmpLCM);
}

int gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}