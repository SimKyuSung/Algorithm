/// 11723С§Че

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

bool s[20];

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, x;
	string c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c[1] == 'd') {
			cin >> x;
			s[x - 1] = true;
		}
		else if (c[0] == 'r') {
			cin >> x;
			s[x - 1] = false;
		}
		else if (c[0] == 'c') {
			cin >> x;
			cout << s[x - 1] << "\n";
		}
		else if (c[0] == 't') {
			cin >> x;
			s[x - 1] = !s[x - 1];
		}
		else if (c[0] == 'e') memset(s, false, sizeof(s));
		else				  memset(s, true, sizeof(s));
	}
}