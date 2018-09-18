/// 16113.½Ã±×³Î

#include <iostream>

using namespace std;

char signal[5][20000];
char patten[10][5][4] = {
		{ // 0
		"###",
		"#.#",
		"#.#",
		"#.#",
		"###" },
		{ // 1
		"xxx",
		"xxx",
		"xxx",
		"xxx",
		"xxx" },
		{ // 2
		"###",
		"..#",
		"###",
		"#..",
		"###" },
		{ // 3
		"###",
		"..#",
		"###",
		"..#",
		"###" },
		{ // 4
		"#.#",
		"#.#",
		"###",
		"..#",
		"..#" },
		{ // 5
		"###",
		"#..",
		"###",
		"..#",
		"###" },
		{ // 6
		"###",
		"#..",
		"###",
		"#.#",
		"###" },
		{ // 7
		"###",
		"..#",
		"..#",
		"..#",
		"..#" },
		{ // 8
		"###",
		"#.#",
		"###",
		"#.#",
		"###" },
		{ // 9
		"###",
		"#.#",
		"###",
		"..#",
		"###" }
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	n /= 5;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++)
			cin >> signal[i][j];
	}

	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < n; j++)
	//		cout << signal[i][j];
	//	cout << endl;
	//}


	for (int j = 0; j < n; j++) {
		if (signal[0][j] == '#' ||
			signal[1][j] == '#' ||
			signal[2][j] == '#' ||
			signal[3][j] == '#' ||
			signal[4][j] == '#') {
			int output = -1;
			for (int num = 0; num < 10; num++) {
				bool pass = 1;
				for (int i = 0; i < 5; i++) {
					for (int jj = 0; jj < 3; jj++) {
						if (signal[i][j + jj] != patten[num][i][jj])
							pass = 0;
					}
				}
				if (pass) {
					output = num;
					break;
				}
			}
			if (output != -1) {
				cout << output;
				j += 3;
			}
			else {
				cout << 1;
				j += 1;
			}
		}
	}
}