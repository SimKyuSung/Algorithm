/// 10987Vowel

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int ans = 0;
	char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++)
		for (int j = 0; j < 5; j++)
			if (line[i] == vowel[j])
				ans++;
	cout << ans << endl;
}