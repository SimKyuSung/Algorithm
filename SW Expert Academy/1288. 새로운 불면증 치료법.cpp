/// 1288. 새로운 불면증 치료법

#include <iostream>
#include <memory.h>

using namespace std;

bool a[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(a, 0, sizeof(a));

		size_t n, nn;
		bool ans = 1;
		cin >> n;

		nn = n;
		while (ans) {
			size_t tmp = nn;
			while (tmp) {
				a[tmp % 10] = 1;
				tmp /= 10;
			}
			ans = 0;
			for (int i = 0; i < 10; i++)
				ans |= !a[i];
			nn += n;
		}
		cout << '#' << t << ' ' << nn  - n << '\n';
	}
}