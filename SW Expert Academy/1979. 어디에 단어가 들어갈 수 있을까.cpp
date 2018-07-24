/// 1979. 어디에 단어가 들어갈 수 있을까

#include <iostream>
#include <memory.h>

using namespace std;

int cross[20][20];
int line[20][20][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(line, 0, sizeof(line));

		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> cross[i][j];

		for (int i = 0; i < n; i++) {
			line[i][0][0] = cross[i][0];
			line[0][i][1] = cross[0][i];
			for (int j = 1; j < n; j++) {
				if (cross[i][j]) {
					line[i][j][0] = line[i][j - 1][0] + cross[i][j];
					line[i][j - 1][0] = 0;
				}
				if (cross[j][i]) {
					line[j][i][1] = line[j - 1][i][1] + cross[j][i];
					line[j - 1][i][1] = 0;
				}
			}
		}

		int counter = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				counter += (line[i][j][0] == k) + (line[i][j][1] == k);

		cout << '#' << t << ' ' << counter << '\n';

	}
}