/// 4766�Ϲ� ȭ�� ����

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed;
	cout.precision(2);

	double a, b;
	cin >> a;

	while (1) {
		cin >> b;
		if (b == 999) break;
		cout << b - a << '\n';
		a = b;
	}
}