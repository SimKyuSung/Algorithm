/// 6987월드컵

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > score(6, vector<int>(3));
vector <bool> result(4, true);

bool solve(int, int);

int main()
{
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				cin >> score[i][j];
				sum += score[i][j];
			}
			if (sum != 5)	result[t] = false;
		}
		if (result[t]) result[t] = solve(0, 1);
	}

	for (bool ans : result)
		cout << ans << " ";
	cout << "\n";
}

// x가 y 상대로
bool solve(int x, int y) {
	if (x == 5)
		return true;
	for (int i = 0; i < 3; i++) {
		score[x][i]--;
		score[y][2 - i]--;
		if (score[x][i] > -1 && score[y][2 - i] > -1) {
			if (y == 5) {
				if (solve(x + 1, x + 2))
					return true;
			}
			else if (solve(x, y + 1))
				return true;
		}
		score[x][i]++;
		score[y][2 - i]++;
	}
	return false;
}