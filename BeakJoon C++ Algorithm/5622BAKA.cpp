// 5622BAKA

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string line;
	int ans = 0;
	cin >> line;
	/*
	abc = 2
	def = 3
	ghi = 4
	...

	*/
	for (int i = 0; i < line.length(); i++) {
		char c = line[i];
		if (c < 'D')
			ans += 3;
		else if (c < 'G')
			ans += 4;
		else if (c < 'J')
			ans += 5;
		else if (c < 'M')
			ans += 6;
		else if (c < 'P')
			ans += 7;
		else if (c < 'T')
			ans += 8;
		else if (c < 'W')
			ans += 9;
		else
			ans += 10;
	}
	cout << ans << endl;
}