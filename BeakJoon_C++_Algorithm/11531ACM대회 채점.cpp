/// 11531ACM대회 채점

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> pennaltyCounter('z' - 'a' + 1, 0);
vector <int> solve('z' - 'a' + 1, -1);

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	while (true) {
		int time;
		char num;
		string result;
		cin >> time;
		if (time == -1) break;
		cin >> num >> result;
		num -= 'A';
		if (solve[num] == -1) {
			if (result[0] == 'w')	 pennaltyCounter[num]++;
			else solve[num] = time + pennaltyCounter[num] * 20;
		}
	}

	int score = 0, pennalty = 0;
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		if (solve[i] > -1) {
			score++;
			pennalty += solve[i];
		}
	}
	cout << score << " " << pennalty;
}