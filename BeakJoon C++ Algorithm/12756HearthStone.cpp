#include <iostream>

using namespace std;

int main()
{
	int damageA, healthA;
	int damageB, healthB;
	cin >> damageA >> healthA;
	cin >> damageB >> healthB;
	// 둘중 하나의 체력이 0이 될때 까지 싸움
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