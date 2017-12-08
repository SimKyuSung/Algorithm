// 2755Grade

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, score = 0, credits = 0;
	string line;

	cin >> n;
	getline(cin, line);
	for (int i = 0; i < n; i++) {
		int credit = 0;
		int grades;
		getline(cin, line);
		for (int k = 0; k < line.length(); k++) {
			if (line[k] == ' ' && credit == 0) {
				credit = line[k + 1] - '0';
				credits += credit;
			}
			else if (line[k] == ' ') {
				grades = (4 - (line[k + 1] - 'A')) * 10;
				if (line[k + 1] == 'F')
					credit = 0;
				else {
					if (line[k + 2] == '+')
						grades += 3;
					else if (line[k + 2] == '-')
						grades -= 3;
				}
			}
		}

		score += credit * grades;
	}
	cout << fixed;
	cout.precision(2);
	// rounding
	double cal = score / (double)credits + 0.05;
	score = (cal * 10);
	cout << score / 100.0 << endl;

}