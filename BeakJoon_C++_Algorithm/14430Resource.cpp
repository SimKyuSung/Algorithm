// 14430Resource

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
int resource[301][301];
int mineral[301][301];

int function(int, int);

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> resource[i][j];
	memset(mineral, -1, sizeof(mineral));
	cout << function(0, 0) << endl;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		cout << mineral[i][j] << " ";
	//	cout << endl;
	//}
}

int function(int x, int y) {
	int &ref = mineral[y][x];
	if (ref != -1)					return ref;
	if (x == m - 1 && y == n - 1)	return ref = resource[y][x];
	else if (x == m - 1)			return ref = resource[y][x] + function(x, y + 1);
	else if (y == n - 1)			return ref = resource[y][x] + function(x + 1, y);
	else							return ref = resource[y][x] + max(function(x, y + 1), function(x + 1, y));
}