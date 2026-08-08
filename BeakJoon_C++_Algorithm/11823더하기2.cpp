/// 11823¥ı«œ±‚2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string n = "";
	string s;
	while (cin >> s) {
		if (s[0] == 'x') break;
		n += s;
	}
	long long ans = 0;
	for (int i = 0; i < n.length(); i++) {
		long long x = 0;
		while (n[i] != ',' && i < n.length()) {
			x *= 10;
			x += (n[i] - '0');
			i++;
		}
		ans += x;
	}
	cout << ans << endl;
}