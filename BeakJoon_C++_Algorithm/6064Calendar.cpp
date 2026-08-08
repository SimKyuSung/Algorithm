// 6064Calendar
#include <iostream>
#include <cstdio>

using namespace std;

int function(int, int, int, int);
int gcd(int, int);
int lcm(int, int);

int main()
{
	ios::sync_with_stdio(false);
	int t;	cin >> t;
	while (t--) {
		int m, n, x, y;		cin >> m >> n >> x >> y;
		printf("%d\n", function(m, n, x, y));
		//for (int i = 1; i < 200; i++)
		//	cout << i << "\t<" << (i - 1) % m + 1 << ":" << (i - 1) % n + 1 << ">" << endl;
	}
}

int function(int m, int n, int x, int y) {
	// must m > n swap
	if (n > m) {
		n ^= m;
		m ^= n;
		n ^= m;

		x ^= y;
		y ^= x;
		x ^= y;
	}
	for (int i = x; i < lcm(m, n); i += m)
		if ((i - 1) % n + 1 == y)
			return i;
	return -1;
}

int gcd(int n, int m) {
	int mod = n % m;
	while (mod > 0)
	{
		n = m;
		m = mod;
		mod = n % m;
	}
	return m;
}

int lcm(int n, int m) {
	return n / gcd(n, m) * m;
}
/*
m n
x y

1:1
2:2
x < m
y < n

10	12
7	2

(3 - 1) % 10 + 1
(9 - 1) % 12 + 1



*/