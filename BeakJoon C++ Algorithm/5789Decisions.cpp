// 5789Decisions

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string line;
	cin >> n;
	while (n--) {
		cin >> line;
		if (line[line.length() / 2] != line[line.length() / 2 - 1])
			cout << "Do-it-Not\n";
		else
			cout << "Do-it\n";
	}
}