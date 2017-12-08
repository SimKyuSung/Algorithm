// 10989Sort3
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num(10004, 0);

int main()
{
	ios::sync_with_stdio(false);
	int n, input;
	cin >> n;

	while (n--) {
		cin >> input;
		num[input]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < num[i]; j++)
			printf("%d\n", i);
}