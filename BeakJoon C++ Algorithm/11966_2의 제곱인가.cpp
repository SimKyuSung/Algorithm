/// 11966 2의 제곱인가?

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// 2의 제곱을 판별해 봅시다.
	// 1. pow연산으로 판별 하는 방법
	for (int i = 0; i < 32; i++) {
		if ((int)pow(2, i) == n) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	// 2. 비트의 갯수를 새는 방법
	/*int counter = 0;
	while (n) {
		counter += n % 2;
		n >>= 1;
	}

	if (counter == 1)	cout << 1;
	else				cout << 0;*/
}