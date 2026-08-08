/// 1259ÆÓ¸°µå·Ò¼ö

#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (true) {
		string test;	cin >> test;
		if (test == "0")	return 0;
		bool palindrome = true;
		for (int i = 0; i < test.length() / 2; i++) {
			if (test[i] != test[test.length() - i - 1])
				palindrome = false;
		}
		if (palindrome)	cout << "yes\n";
		else			cout << "no\n";
	}
}