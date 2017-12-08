// 3058Even

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t, input;
	cin >> t;
	while (t--) {
		int total = 0, mininmum = 0x7FFFFFFF;
		for (int i = 0; i < 7; i++) {
			cin >> input;
			if (input % 2 == 0) {
				total += input;
				mininmum = min(mininmum, input);
			}
		}
		printf("%d %d\n", total, mininmum);
	}
}