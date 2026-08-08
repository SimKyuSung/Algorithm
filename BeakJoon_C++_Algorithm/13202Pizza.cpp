#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

long double pi = 3.1415926;
// 각 꼭지점 별 배율

int main()
{
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		long long a, b;
		double c;
		int k;

		double r0;
		double r1, r2, r3;

		double ans = 0;

		double d1, d2, d3;
		double ax, bx;

		cin >> a >> b >> k;
		// 내접원의 반지름
		// r = 2S / a + b + c

		c = sqrt((a * a) + (b * b));
		r0 = (a * b) / (double)(a + b + c);
		// 각 꼭지점 별로 배율이 있을거 같다.
		// 헤론의 공식
		//ax = b + c;
		//bx = (6 * c) - b;
		//d1 = (0 - sqrt((bx * bx) - (4 * ax * ax)) + bx) / (2 * ax);

		/*ax = a + c;
		bx = (6 * c) - a;
		d2 = (0 - sqrt((bx * bx) - (4 * ax * ax)) + bx) / (2 * ax);*/

		ax = sqrt((c - a) / (2 * c));
		bx = sqrt((c - b) / (2 * c));

		d1 = (1 - ax) / (1 + ax);
		d2 = (1 - bx) / (1 + bx);
		d3 = (sqrt(2) - 1) / (sqrt(2) + 1);

		r1 = r0 * d1;
		r2 = r0 * d2;
		r3 = r0 * d3;

		/*cout << c << endl;
		cout << r0 << endl;
		cout << d1 << endl;
		cout << d2 << endl;
		cout << d3 << endl;*/

		ans = r0;

		for (int i = 1; i < k; i++) {
			// r1 r2 r3 중 가장 큰 값을 찾는다.
			if (r1 > r2) {
				if (r1 > r3) {
					ans = r1;
					r1 = r1 * d1;
				}
				else {
					ans = r3;
					r3 = r3 * d3;
				}
			}
			else {
				if (r2 > r3) {
					ans = r2;
					r2 = r2 * d2;
				}
				else {
					ans = r3;
					r3 = r3 * d3;
				}
			}
		/*	
			ans = ans * ans * pi;
			cout.precision(10);
			cout << fixed << ans << "\t" << ch << '\n';
		*/
		}
		ans = ans * ans * pi;
		cout.precision(10);
		cout << fixed << ans << '\n';

		//printf("%lld\n", ans * ans * pi);
	}
}