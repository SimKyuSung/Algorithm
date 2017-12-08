#include <iostream>
#include <string>

using namespace std;

void Base8To2(string Base8) {
	if ((Base8[0] - '0') & 4) {
		cout << 1;
		if ((Base8[0] - '0') & 2)
			cout << 1;
		else cout << 0;
		if ((Base8[0] - '0') & 1)
			cout << 1;
		else cout << 0;
	}
	else if ((Base8[0] - '0') & 2) {
		cout << 1;
		if ((Base8[0] - '0') & 1)
			cout << 1;
		else cout << 0;
	}
	else if ((Base8[0] - '0') & 1)
		cout << 1;
	else cout << 0;
	for (int i = 1; i < Base8.size(); i++) {
		for (int c = 0; c < 3; c++)
			if (((Base8[i] - '0') << c) & 4)
				cout << 1;
			else
				cout << 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	string Base8;
	cin >> Base8;
	Base8To2(Base8);
	cout << '\n';
}