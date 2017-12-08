// 2864Between5to6

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	int maxA, maxB;
	int minA, minB;
	cin >> a >> b;
	for (int i = 1000000; i > 0; i /= 10) {
		if ((a / i) % 10 == 6)
			a -= i;
		if ((b / i) % 10 == 6)
			b -= i;
	}
	printf("%d ", a + b);
	for (int i = 1000000; i > 0; i /= 10) {
		if ((a / i) % 10 == 5)
			a += i;
		if ((b / i) % 10 == 5)
			b += i;
	}
	printf("%d\n", a + b);
}