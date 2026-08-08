// 11048MoveMap

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dpMap[1004][1004];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> dpMap[i][j];

	for (int j = 1; j < m; j++)
		dpMap[0][j] += dpMap[0][j - 1];
	for (int i = 1; i < n; i++)
		dpMap[i][0] += dpMap[i - 1][0];

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dpMap[i][j] += max(dpMap[i - 1][j], dpMap[i][j - 1]);

	printf("%d\n", dpMap[n - 1][m - 1]);
}
