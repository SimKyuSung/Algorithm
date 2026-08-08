// 11655ROT13

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	for (int i = 0; i < line.length(); i++) {
		if (line[i] >= 's')
			line[i] -= 13;
		else if (line[i] >= 'a') {
			line[i] += 13;
			if (line[i] > 'z')
				line[i] -= 26;
		}
		else if (line[i] >= 'A') {
			line[i] += 13;
			if (line[i] > 'Z')
				line[i] -= 26;
		}
	}
	cout << line << endl;
}

/*
Baekjoon Online Judge

Onrxwbba Bayvar Whqtr
*/