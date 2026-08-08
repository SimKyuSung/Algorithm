/// 2058. 자릿수 더하기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, nn = 0;
	cin >> n;

	nn = 0;
	while (n) {
		nn += n % 10;
		n /= 10;
	}
	n = nn;

	cout << n << '\n';
}