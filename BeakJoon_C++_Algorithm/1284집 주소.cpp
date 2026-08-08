/// 1284집 주소

#include <iostream>

using namespace std;

int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		int ans = 0;
		while (n) {
			int x = n % 10;
			if (x == 0)			ans += 5;
			else if (x == 1)	ans += 3;
			else				ans += 4;
			n /= 10;
		}
		cout << ans + 1 << endl;
	}
}

/*
0: 4
1: 2
2~: 3
간격 1
*/