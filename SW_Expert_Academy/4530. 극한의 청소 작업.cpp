/// 4530. 극한의 청소 작업

#include <iostream>

#define endl '\n'

using namespace std;

long long counter4(long long);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		long long a, b, ans = 0;
		bool zeroMinus = 0;

		cin >> a >> b;
		if (a < 0 && 0 < b)
			zeroMinus = 1;
		a -= counter4(a);
		b -= counter4(b);
		ans = b - a;
		cout << '#' << t << ' ' << ans - zeroMinus << endl;
	}
}

long long counter4(long long a) {
	bool flag = 0;
	if (a < 0) {
		a = -a;
		flag = 1;
	}

	long long ret = 0, x = 0, ten = 1;
	while (a) {
		ret += a % 10 * x;
		if (a % 10 > 4)
			ret += ten - x;
		a /= 10;
		x = 9 * x + ten;
		ten *= 10;
	}

	if (flag)
		ret = -ret;
	return ret;
}
/*
4가 들어간 숫자 주어지지 않음

0~3		5~9			0			1
00~30	50~90		cy			cy - 1 + 10
000~300	500~900		19 * cy		19 * (cy - 1) + 100
0000 ~ 3000	5000~9000	271 * cy	271 * (cy - 1) + 1000


*/

// 789789789789
/*
789789789780	1
789789789700	10 + 8
789789789000	100 +

*/