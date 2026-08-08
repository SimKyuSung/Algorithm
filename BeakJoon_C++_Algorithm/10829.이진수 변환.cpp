/// 10829.이진수 변환

#include <iostream>

#define endl '\n'

using namespace std;

int num[48];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n, counter = 0;
	cin >> n;

	if (n == 0)
		cout << 0;
	while (n) {
		num[counter++] = n % 2;
		n /= 2;
	}
	while (counter--)
		cout << num[counter];
	cout << endl;
}