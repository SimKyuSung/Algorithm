/// 2019. �������

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, bitMask = 1;
	cin >> n;

	cout << bitMask << ' ';
	bitMask <<= 1;
	while (n--) {
		cout << bitMask << ' ';
		bitMask <<= 1;
	}
}