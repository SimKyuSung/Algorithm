#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long n, divisor, minimum = 1000004, maximum = 1;
	cin >> n;
	// 가장 작은 약수와 가장 큰 약수를 곱하면 원래의 수가 나온다.
	while (n--) {
		cin >> divisor;
		minimum = min(minimum, divisor);
		maximum = max(maximum, divisor);
	}
	cout << minimum * maximum << "\n";
}