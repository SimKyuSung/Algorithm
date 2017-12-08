/// 13235ÆÓ¸°µå·Ò (Palindromes)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	cin >> line;
	int n = line.length();
	bool ans = true;
	for (int i = 0; i < n / 2; i++) {
		if (line[i] != line[n - i - 1])
			ans = false;
	}

	if (ans) cout << "true\n";
	else	 cout << "false\n";
}