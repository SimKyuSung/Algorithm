// 10809Find

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line;
	cin >> line;
	vector<int> alpha(26, -1);
	for (int i = line.length() - 1; i > -1; i--) {
		char c = line[i];
		alpha[c - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";
	cout << endl;
}
