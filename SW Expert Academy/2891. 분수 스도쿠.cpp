/// 2891. ºĞ¼ö ½ºµµÄí

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int s[6][6][2];

bool f[6][6];

bool c1[6][9];
bool c2[6][9];
bool c3[3][2][9];
bool c4[6][6][2];

bool solve(int, bool);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		
		memset(s, 0, sizeof(s));
		memset(f, 0, sizeof(f));

		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));
		memset(c4, 0, sizeof(c4));

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				string line;
				cin >> line;
				int input1 = 0, input2 = 0;

				if (line[0] != '-')
					input1 = line[0] - '0';
				if (line.size() > 1) {
					f[i][j] = true;
					if (line[2] != '-')
						input2 = line[2] - '0';
				}
				else
					c4[i][j][1] = true;

				s[i][j][0] = input1;
				s[i][j][1] = input2;

				if (input1) {
					c1[i][input1 - 1] = true;
					c2[j][input1 - 1] = true;
					c3[i / 2][j / 3][input1 - 1] = true;
					c4[i][j][0] = true;
				}
				if (input2) {
					c1[i][input2 - 1] = true;
					c2[j][input2 - 1] = true;
					c3[i / 2][j / 3][input2 - 1] = true;
					c4[i][j][1] = true;
				}
			}
		}

		solve(0, 0);

		cout << "#" << t << "\n";
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				cout << s[i][j][0];
				if (f[i][j])
					cout << '/' << s[i][j][1];
				cout << ' ';
			}
			cout << '\n';
		}
	}
}

bool solve(int num, bool next) {
	bool ans = false;
	int x = num % 6;
	int y = num / 6;

	if (num == 36)		return true;
	if (c4[y][x][next])	return solve(num + next, !next);
	for (int i = 0; i < 9; i++) {
		if (!c1[y][i] && !c2[x][i] && !c3[y / 2][x / 3][i]) {
			if (next && s[y][x][0] > i + 1)
				continue;
			if (!next && f[y][x] && c4[y][x][1] && s[y][x][1] < i + 1)
				break;
			c1[y][i] = true;
			c2[x][i] = true;
			c3[y / 2][x / 3][i] = true;
			s[y][x][next] = i + 1;
			if (solve(num + next, !next)) return true;
			c1[y][i] = false;
			c2[x][i] = false;
			c3[y / 2][x / 3][i] = false;
		}
	}
	return false;
}