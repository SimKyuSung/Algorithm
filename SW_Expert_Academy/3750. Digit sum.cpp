/// 3750. Digit sum

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		size_t n, nn;
		cin >> n;

		while (n > 9) {
			nn = 0;
			while (n) {
				nn += n % 10;
				n /= 10;
			}
			n = nn;
		}

		cout << '#' << t << ' ' << n << '\n';
	}
}