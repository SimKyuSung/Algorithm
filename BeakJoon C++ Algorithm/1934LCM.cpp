// 1934LCM

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		printf("%d\n", lcm(a, b));
	}
}

int gcd(int n, int m) {
	int r;
	while (true) {
		r = m % n;
		if (r == 0)
			return n;
		else {
			m = n;
			n = r;
		}
	}
}

int lcm(int n, int m) {
	return n * m / gcd(n, m);
}