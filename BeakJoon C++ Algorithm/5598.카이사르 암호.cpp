/// 5598.카이사르 암호

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string CaesarCipher;
	cin >> CaesarCipher;
	for (int i = 0; i < CaesarCipher.size(); i++) {
		if (CaesarCipher[i] > 'C')
			CaesarCipher[i] -= 3;
		else
			CaesarCipher[i] += 23;
	}
	cout << CaesarCipher << endl;
}