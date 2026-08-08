/// 15667_2018 연세대학교 프로그래밍 경진대회

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n;
	for (int k = 1; k <= 100; k++) {
		if (k * k + k + 1 == n) {
			cout << k << '\n';
			break;
		}
	}
	return 0;
}

/*

k^2 + k + 1 = n
x^2 + k + 1 - n = 0;
k = ?

*/