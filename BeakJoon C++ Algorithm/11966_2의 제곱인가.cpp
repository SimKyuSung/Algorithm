/// 11966 2�� �����ΰ�?

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// 2�� ������ �Ǻ��� ���ô�.
	// 1. pow�������� �Ǻ� �ϴ� ���
	for (int i = 0; i < 32; i++) {
		if ((int)pow(2, i) == n) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	// 2. ��Ʈ�� ������ ���� ���
	/*int counter = 0;
	while (n) {
		counter += n % 2;
		n >>= 1;
	}

	if (counter == 1)	cout << 1;
	else				cout << 0;*/
}