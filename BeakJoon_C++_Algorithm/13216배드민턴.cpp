/// 13216╧Х╣Е╧нео

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	int ab[2] = { 0, 0 };
	char winner;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		ab[line[i] - 'A']++;
		if (ab[0] == 21) {
			cout << ab[0] << '-' << ab[1] << '\n';
			winner = 'A';
			ab[0] = ab[1] = 0;
		}
		else if (ab[1] == 21) {
			cout << ab[0] << '-' << ab[1] << '\n';
			winner = 'B';
			ab[0] = ab[1] = 0;
		}
	}
	cout << winner;
}