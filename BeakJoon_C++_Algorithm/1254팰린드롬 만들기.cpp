/// 1254팰린드롬 만들기

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;	cin >> line;
	int ans = line.length();
	
	int mid = ans / 2;

	for (int i = mid; i < line.length(); i++) {
		bool isPalindrome = true;
		for (int j = 0; i + j < line.length(); j++) {
			int tmp = (ans + 1) % 2;
			if (line[i - j - tmp] != line[i + j]) {
				isPalindrome = false;
				ans++;
				break;
			}
		}
		if (isPalindrome)
			break;
		if (ans % 2)
			i--;
	}
	cout << ans << endl;
}

/*


abab
ababa
5

abc
abcba
5

abcabc
abcabcbacba
11

ababdba
ababdbaba
9

012345678910
abxyzabtyba
21

0123456789
abxyzabtyb

abba
aba

abctyaba

*/