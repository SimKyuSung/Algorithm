/// 14411ÇÕÁıÇÕ

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int data[5000002] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	int max_x = 0;
	int min_x = 5000002;
	for (int i = 0; i < n; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		if (data[input1 / 2] < input2)
			data[input1 / 2] = input2;
		max_x = max(max_x, input1 / 2);
		min_x = min(min_x, input1 / 2);
	}

	unsigned long long ans = 0;
	int max_y = data[max_x];
	ans += (unsigned long long)max_y * max_x;
	for (int i = max_x - 1; i >= min_x; i--) {
		if (data[i] > max_y) {
			ans += (unsigned long long)(data[i] - max_y) * i;
			max_y = data[i];
		}
	}
	cout << ans * 2 << "\n";
}

/*
10000000

5000000

*/