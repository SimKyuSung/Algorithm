// 2588ststs2

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	vector<int> num(5);
	int mean = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		mean += num[i];
	}
	mean = mean / 5;
	sort(num.begin(), num.end());
	printf("%d\n%d\n", mean, num[2]);
}