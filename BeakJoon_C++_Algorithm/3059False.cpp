/// 3059False

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
	int t;	cin >> t;
	while (t--) {
		int ans = 0;
		bool alpha[26];
		memset(alpha, false, sizeof(alpha));
		for (int i = 0; i < 26; i++)
			ans += i + 'A';
		string line;
		cin >> line;
		for (int i = 0; i < line.length(); i++)
			alpha[line[i] - 'A'] = true;
		for (int i = 0; i < 26; i++)
			if (alpha[i])
				ans -= i + 'A';
		cout << ans << endl;
	}
}