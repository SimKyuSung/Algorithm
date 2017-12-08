/// 1072∞‘¿”

#include <iostream>

using namespace std;

long long counter(long long, long long);

int main()
{
	long long x, y, z;
	while (cin >> x >> y) {
		z = y * 100 / x;
		if (z > 98) {
			cout << -1 << endl;
			continue;
		}
		z = counter(x, y);
		cout << z << endl;
	}
	return 0;
}

//long long counter(long long x, long long y) {
//	long long t = (x * x) / (double)(99 * x - 100 * y);
//	return t;
//}

long long counter(long long x, long long y) {
	long long l = 1, h = 0xffffffff;
	long long mid;
	long long z = y * 100 / x;
	long long zz;
	while (l <= h) {
		mid = (l + h) / 2;
		//cout << mid << endl;
		zz = (y + mid) * 100 / (x + mid);
		if (z < zz)
			h = mid - 1;
		else
			l = mid + 1;
	}
	return h + 1;
}

/*
y / x + 1 / 100 = (y + t) / (x + t)

t = (x * x) / (100x - 100y + x)

1 ~ 1000000000
0 ~ 1000000000
*/