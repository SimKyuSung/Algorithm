/// 2025. N�ٵ���

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (n + 1) * n / 2;
}

/*
overflow ���� ���

(A + B) / 2
(B - A + 2A) / 2
(B - A) / 2 + A

*/