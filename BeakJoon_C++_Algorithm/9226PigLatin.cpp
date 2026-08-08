// 9226PigLatin

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
	ios::sync_with_stdio(false);
	while (true) {
		string line;
		cin >> line;
		if (line == "#")
			break;

		int index = 0;
		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				index = i;
				break;
			}
		}
		for (int i = index; i < line.length(); i++)
			printf("%c", line[i]);
		for (int i = 0; i < index; i++)
			printf("%c", line[i]);
		printf("ay\n");
	}

}