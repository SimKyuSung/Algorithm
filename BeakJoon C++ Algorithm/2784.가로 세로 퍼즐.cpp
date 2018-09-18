/// 2784.가로 세로 퍼즐

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

vector <string> puzzle(6);
vector <int> x = { 0, 1, 2, 3, 4, 5 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 6; i++)
		cin >> puzzle[i];
	
	bool ans = 0;
	do {
		ans = 1;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (puzzle[x[i]][j] != puzzle[x[j + 3]][i])
					ans = 0;
			}
		}
	} while (!ans && next_permutation(x.begin(), x.end()));
	if (ans)
		for (int i = 0; i < 3; i++)
			cout << puzzle[x[i]] << endl;
	else
		cout << 0 << endl;
}

/*

ABC
DEF
GHI

  3 4 5
0
1
2
*/