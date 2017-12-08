/// 12279유리수 트리 (Large)

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T;	cin >> T;
	for (int t = 1; t <= T; t++) {
		int id;
		cin >> id;
		unsigned long long n, p, q, bitMask;
		if (id == 1) {
			cin >> n;
			p = 1, q = 1;
			bitMask = 2;
			while ((n >> 1) > bitMask - 1) {
				bitMask <<= 1;
			}
			n = n - bitMask;
			// n 호수
			bitMask >>= 1;
			while (bitMask) {
				if (bitMask & n)	p = p + q;
				else				q = p + q;
				bitMask >>= 1;
			}
			printf("Case #%d: %llu %llu\n", t, p, q);
		}
		else {
			cin >> p >> q;
			n = 0;
			bitMask = 1;
			while (p != q) {
				if (q > p) {
					q = q - p;
				}
				else {
					p = p - q;
					n = n | bitMask;
				}
				bitMask <<= 1;
			}
			printf("Case #%d: %llu\n", t, n + bitMask);
		}
	}
}