/// 1926. 간단한 369게임

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		// 숫자 분해
		int tmp = i;
		int c = 0;
		while (tmp) {
			if ((tmp % 10) % 3 == 0 && tmp % 10 != 0)
				c++;
			tmp /= 10;
		}
		if (c)
			while (c--)
				cout << '-';
		else
			cout << i;
		cout << ' ';
	}
}