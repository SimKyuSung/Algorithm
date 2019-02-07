/// 13015.º° Âï±â - 23

#include <iostream>
#include <memory.h>

#define endl '\n'

using namespace std;

char starX[200][400];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i = 0, j = 0;
	cin >> n;
	while (j < n)
		starX[0][j++] = '*';
	while (j < 3 * n - 3)
		starX[0][j++] = ' ';
	while (j < 4 * n - 3)
		starX[0][j++] = '*';

	i = 1;
	while (i < n) {
		j = 0;
		while (j < i)
			starX[i][j++] = ' ';
		starX[i][j++] = '*';
		while (j < i + n - 1)
			starX[i][j++] = ' ';
		starX[i][j++] = '*';

		while (j < 3 * n - 3 - i)
			starX[i][j++] = ' ';
		
		if (i != n - 1)
			starX[i][j++] = '*';
		
		while (j < 4 * n - 4 - i)
			starX[i][j++] = ' ';
		starX[i][j++] = '*';
		i++;
	}

	for (int i = 0; i < n; i++)
		memcpy(starX[n + i - 1], starX[n - i - 1], sizeof(starX[i]));
	for (int i = 0; i < 2 * n - 1; i++)
		cout << starX[i] << endl;
}
/*

2 -> 1


5 -> 7

2n + (n - 1) * 2
[2n - 1][4n - 2]

10 + 2
9
8
7

8 + 1
7
6

*/