// 2675Repeating

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int repeat;
		cin >> repeat;
		string line;
		cin >> line;

		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			for (int j = 0; j < repeat; j++)
				printf("%c", c);
		}
		printf("\n");
	}
}
