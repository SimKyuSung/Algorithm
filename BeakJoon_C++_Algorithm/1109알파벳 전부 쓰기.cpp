/// 1109알파벳 전부 쓰기

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

bool alpha[26];

int main()
{
	int n;	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		
		memset(alpha, false, sizeof(alpha));
		for (int i = 0; i < s.length(); i++)
			if ('a' <= s[i] && s[i] <= 'z')	alpha[s[i] - 'a'] = true;

		bool pangram = true;
		for (int i = 0; i < 26; i++)
			if (!alpha[i])	pangram = false;

		if (pangram)	cout << "pangram\n";
		else {
			cout << "missing ";
			for (int i = 0; i < 26; i++)
				if (!alpha[i])
					cout << char(i + 'a');
			cout << "\n";
		}
	}
}