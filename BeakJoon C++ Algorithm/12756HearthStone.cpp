#include <iostream>

using namespace std;

int main()
{
	int damageA, healthA;
	int damageB, healthB;
	cin >> damageA >> healthA;
	cin >> damageB >> healthB;
	// ���� �ϳ��� ü���� 0�� �ɶ� ���� �ο�
	while (healthA > 0 && healthB > 0) {
		healthA -= damageB;
		healthB -= damageA;
	}
	if (healthA < 1 && healthB < 1)
		cout << "DRAW\n";
	else if (healthB < 1)
		cout << "PLAYER A\n";
	else
		cout << "PLAYER B\n";
}