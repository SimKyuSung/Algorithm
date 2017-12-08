// 5347LCM

#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long gcd(unsigned long long, unsigned long long);
unsigned long long lcm(unsigned long long, unsigned long long);

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		unsigned long long a, b;
		cin >> a >> b;
		printf("%d\n", lcm(a, b));
	}
}

unsigned long long gcd(unsigned long long n, unsigned long long m) {
	unsigned long long r;
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

unsigned long long lcm(unsigned long long n, unsigned long long m) {
	return n * m / gcd(n, m);
}