// 1356Number

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string number;
	bool ans = false;
	cin >> number;
	for (int i = 0; i < number.length() - 1; i++) {
		int prefix = 1, suffix = 1;
		for (int j = 0; j <= i; j++)
			prefix *= (number[j] - '0');
		for (int j = i + 1; j < number.length(); j++)
			suffix *= (number[j] - '0');
		if (prefix == suffix)
			ans = true;
	}
	if (ans)	cout << "YES\n";
	else		cout << "NO\n";
}