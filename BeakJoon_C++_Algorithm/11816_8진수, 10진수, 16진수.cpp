/// 11816_8진수, 10진수, 16진수

#include <iostream>
#include <string>

using namespace std;

int hax[128];

int main()
{
	int ans = 0, base = 1, i, two = 0;
	string n;	cin >> n;
	if (n[0] != '0')	cout << n;
	else {
		for (i = '0'; i <= '9'; i++)	hax[i] = i - '0';
		for (i = 'a'; i <= 'f'; i++)	hax[i] = i - 'a' + 10;
		if (n[1] == 'x') two = 1;
		i = n.length() - 1;
		while (i > two) {
			ans += base * hax[n[i]];
			i--, base *= (8 << two);
		}
		cout << ans;
	}
}