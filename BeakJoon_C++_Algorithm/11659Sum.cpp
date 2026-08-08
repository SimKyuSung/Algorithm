// 11659Sum

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	vector<int> dpTable;
	int n, m, input, i, j;
	cin >> n >> m;
	dpTable.push_back(0);
	for (int k = 0; k < n; k++) {
		cin >> input;
		dpTable.push_back(dpTable[k] + input);
	}
	while (m--) {
		cin >> i >> j;
		printf("%d\n", dpTable[j] - dpTable[i - 1]);
	}
}

/*
5 3
5 4 3 2 1
1 3
2 4
5 5

12
9
1
*/