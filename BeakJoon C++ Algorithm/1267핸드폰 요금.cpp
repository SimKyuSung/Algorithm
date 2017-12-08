/// 1267핸드폰 요금

#include <iostream>

using namespace std;

int main()
{
	int n;	cin >> n;
	unsigned long long y = 0, m = 0;
	while (n--) {
		unsigned long long input;	cin >> input;
		y += ((input + 30) / 30) * 10;
		m += ((input + 60) / 60) * 15;
	}
	if (y > m)		cout << "M " << m << endl;
	else if (m > y)	cout << "Y " << y << endl;
	else			cout << "Y M " << y << endl;
}