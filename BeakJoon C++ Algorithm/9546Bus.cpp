// 9546Bus

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int k;
		unsigned int ans = 0;
		cin >> k;
		for (int i = 0; i < k; i++)
			ans = ans * 2 + 1;
		cout << ans << endl;
	}
}

/*
2
1
3

1
7

x = x / 2 - 0.5

x + 0.5 = x / 2
2 * x + 1 = x
*/