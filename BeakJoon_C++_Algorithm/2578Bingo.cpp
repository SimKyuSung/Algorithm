//2578Bingo

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
	int input;
	vector<int> bingo[5];
	vector<bool> hex[5];
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> input;
			bingo[i].push_back(input);
			hex[i].push_back(false);
		}
	}
	bool horizon[5];
	bool vertical[5];
	bool diagonal[2];
	memset(horizon, false, sizeof(horizon));
	memset(vertical, false, sizeof(vertical));
	memset(diagonal, false, sizeof(diagonal));

	int counti = 0;
	vector<int> ans;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> input;
			int x, y;
			for (x = 0; x < 5; x++)
				for (y = 0; y < 5; y++)
					if (input == bingo[y][x])
						hex[y][x] = true;

			counti++;

			// horizon
			for (x = 0; x < 5; x++)
				if (hex[0][x] && hex[1][x] && hex[2][x] && hex[3][x] && hex[4][x])
					horizon[x] = true;
			// vertical
			for (y = 0; y < 5; y++)
				if (hex[y][0] && hex[y][1] && hex[y][2] && hex[y][3] && hex[y][4])
					vertical[y] = true;
			// diagonal
			if (hex[0][0] && hex[1][1] && hex[2][2] && hex[3][3] && hex[4][4])
				diagonal[0] = true;
			if (hex[0][4] && hex[1][3] && hex[2][2] && hex[3][1] && hex[4][0])
				diagonal[1] = true;
			
			int counter = 0;
			for (x = 0; x < 5; x++) {
				if (horizon[x])
					counter++;
				if (vertical[x])
					counter++;
			}
			if (diagonal[0])
				counter++;
			if (diagonal[1])
				counter++;
			if (counter > 2) {
				ans.push_back(counti);
			}
		}
	}
	cout << ans[0] << endl;
	
}