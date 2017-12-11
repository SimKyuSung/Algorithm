/// 13311행운의 편지

#include <iostream>

size_t gcd(size_t, size_t);
size_t lcm(size_t, size_t);

int main()
{
	size_t ans = 1;
	for (int i = 2; i < 11; i++) {
		ans = lcm(ans, i);
		std::cout << ans - 1<< '\n';
	}
}

size_t gcd(size_t n, size_t m) {
	size_t r;
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

size_t lcm(size_t n, size_t m) {
	return n * m / gcd(n, m);
}