/// 1919애너그램 만들기

#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>

using namespace std;

int abcCount[26];

int main()
{
	memset(abcCount, 0, sizeof(abcCount));

	string line[2];
	cin >> line[0] >> line[1];

	for (int i = 0; i < line[0].length(); i++)
		abcCount[line[0][i] - 'a']++;

	for (int i = 0; i < line[1].length(); i++)
		abcCount[line[1][i] - 'a']--;

	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans += abs(abcCount[i]);
	cout << ans;

}