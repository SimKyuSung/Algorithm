#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int alphabet[26];

int main()
{
	ios::sync_with_stdio(false);
	string line;
	int ans, maximum = 0, tmp = 0;
	cin >> line;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] > 'a' - 1)	alphabet[line[i] - 'a']++;
		else					alphabet[line[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (maximum < alphabet[i]) {
			maximum = alphabet[i];
			ans = i;
		}
	}
	for (int i = 0; i < 26; i++)
		if (maximum == alphabet[i])
			tmp++;
	if (tmp > 1)	printf("?\n");
	else			printf("%c\n", ans + 'A');
}