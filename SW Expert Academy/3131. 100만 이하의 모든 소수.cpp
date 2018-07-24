/// 3131. 100�� ������ ��� �Ҽ�

#include <iostream>
#include <bitset>

using namespace std;

const int n = 1000001;
bitset <n> a;

int main()
{
	for (int i = 2; i < n; i++) {
		if (!a[i]) {
			cout << i << ' ';
			for (int j = i; j < n; j += i)
				a[j] = 1;
		}
	}
}