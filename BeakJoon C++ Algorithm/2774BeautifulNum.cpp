// 2774BeautifulNum

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		vector<bool> beautiful(10, false);
		int x, ans = 0;
		cin >> x;
		while (x > 0) {
			beautiful[x % 10] = true;
			x /= 10;
		}
		for (x = 0; x < 10; x++)
			if (beautiful[x])
				ans++;
		cout << ans << endl;
	}
}

/*
2
7
122
*/