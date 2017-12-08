/// 2239스도쿠

#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9];

vector < vector <bool> > c1;
vector < vector <bool> > c2;
vector < vector < vector <bool> > > c3;
vector < vector <bool> > c4;

bool solve(int);

int main()
{
	c1.resize(9, vector <bool>(10, false));
	c2.resize(9, vector <bool>(10, false));
	c3.resize(3, vector < vector < bool > >(3, vector < bool > (10, false)));
	c4.resize(9, vector <bool>(9, false));

	for (int i = 0; i < 9; i++) {
		string line;	cin >> line;
		for (int j = 0; j < 9; j++) {
			int num = line[j] - '0';
			sudoku[i][j] = num;
			if (num) {
				c1[i][num] = true;
				c2[j][num] = true;
				c3[i / 3][j / 3][num] = true;
				c4[i][j] = true;
			}
		}
	}

	solve(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j];
		cout << "\n";
	}
}

bool solve(int num) {
	bool ans = false;
	int x = num % 9;
	int y = num / 9;
	if (num == 81)	return true;
	if (c4[y][x])	return solve(num + 1);

	// 해당 칸에 0 ~ 9 까지 넣어 본다 (가능 한게 없으면 false return;
	for (int i = 1; i < 10; i++) {
		if ((!c1[y][i]) && (!c2[x][i]) && (!c3[y / 3][x / 3][i])) {
			c1[y][i] = true;
			c2[x][i] = true;
			c3[y / 3][x / 3][i] = true;
			sudoku[y][x] = i;
			if (solve(num + 1)) return true;
			c1[y][i] = false;
			c2[x][i] = false;
			c3[y / 3][x / 3][i] = false;
		}
	}
	return false;
}