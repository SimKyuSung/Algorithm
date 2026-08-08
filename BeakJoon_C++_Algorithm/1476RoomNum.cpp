// 1476RoomNum

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> numCounter(10, 0);

int function(int);
void swap(int&, int&);

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	printf("%d\n", function(n));
}

int function(int n) {
	int ans = 0;
	while (n > 0) {
		numCounter[n % 10]++;
		n /= 10;
	}
	swap(numCounter[6], numCounter[8]);

	for (int i = 0; i < 8; i++)
		ans = max(ans, numCounter[i]);

	int six_nine = numCounter[8] + numCounter[9];
	if (six_nine % 2)
		six_nine++;
	if (six_nine - ans > 0)
		ans += (six_nine - ans) / 2;
	return ans;
}

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}