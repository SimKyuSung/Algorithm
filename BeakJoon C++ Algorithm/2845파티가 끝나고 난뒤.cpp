/// 2845��Ƽ�� ������ ����

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int l, p;	cin >> l >> p;
	l *= p;
	for (int i = 0; i < 5; i++) {
		cin >> p;
		cout << p - l << " ";
	}
}