/// 1933. ������ N �� ���

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cout << i << ' ';
	}
}

/*

�Ҽ� Array�� ����� ����� ������ �������� ����

*/