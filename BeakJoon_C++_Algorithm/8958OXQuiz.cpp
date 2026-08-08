#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		string ans;
		int score = 0;
		int acc = 0;
		cin >> ans;
		size_t size = ans.size();
		for (int i = 0; i < size; i++) {
			if (ans[i] == 'O')
				score += ++acc;
			else
				acc = 0;
		}
		cout << score << endl;
	}
}