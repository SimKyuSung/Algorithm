/// 1213ÆÓ¸°µå·Ò

#include <iostream>
#include <string>

using namespace std;

int alphaCounter[26] = { 0, };

int main()
{
	string line;	cin >> line;

	if (line.length() == 1) {
		cout << line << endl;
		return 0;
	}

	for (int i = 0; i < line.length(); i++)
		alphaCounter[line[i] - 'A']++;

	bool isPalindrome = true;
	for (int i = 0; i < 26; i++)
		if (alphaCounter[i] % 2)
			isPalindrome = false;

	if (isPalindrome) {
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < alphaCounter[i] / 2; j++)
				cout << (char)(i + 'A');
		for (int i = 25; i >= 0; i--)
			for (int j = 0; j < alphaCounter[i] / 2; j++)
				cout << (char)(i + 'A');
		cout << endl;
	}
	else	cout << "I'm Sorry Hansoo\n";
	return 0;
}