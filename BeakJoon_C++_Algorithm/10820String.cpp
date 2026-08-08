/// 10820String

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line)) {
		int lower = 0, upper = 0, num = 0, space = 0;
		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			if (c == ' ')		space++;
			else if (c <= '9')	num++;
			else if (c <= 'Z')	upper++;
			else				lower++;
		}
		printf("%d %d %d %d\n", lower, upper, num, space);
	}
}