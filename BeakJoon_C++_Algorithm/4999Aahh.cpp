// 4999Aaah
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string aaah;
	string aah;
	cin >> aaah;
	cin >> aah;
	if (aaah.length() >= aah.length())
		cout << "go\n";
	else cout << "no\n";
}