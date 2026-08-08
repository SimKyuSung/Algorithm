/// 2816.디지털 티비

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
vector <string> c;
string ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, i;
	cin >> n;
	c.resize(n);
	for (i = 0; i < n; i++)
		cin >> c[i];

	// kbs1
	for (i = 0; c[i] != "KBS1"; i++)
		ans += '1';
	while (i--) {
		ans += '4';
		swap(c[i], c[i + 1]);
	}

	// kbs2
	n = 0;
	for (i = 0; c[i] != "KBS2"; i++)
		ans += '1';
	while (--i)
		ans += '4';
	cout << ans << endl;
}

/*

mbc
kbs2
kbs1

3
kbs2
mbc
kbs1

3
kbs2
kbs1
mbc

2
커서 올리고 내리고

4
kbs1
kbs2
mbc





*/