#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long n, divisor, minimum = 1000004, maximum = 1;
	cin >> n;
	// ���� ���� ����� ���� ū ����� ���ϸ� ������ ���� ���´�.
	while (n--) {
		cin >> divisor;
		minimum = min(minimum, divisor);
		maximum = max(maximum, divisor);
	}
	cout << minimum * maximum << "\n";
}