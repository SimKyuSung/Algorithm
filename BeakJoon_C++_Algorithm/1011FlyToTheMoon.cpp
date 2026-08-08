// 1011FlyToTheMoon

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int x, y, dis;
		unsigned long long ans = 1;
		cin >> x >> y;
		dis = y - x;
		// (n - 1) < dis <= n
		// = n * (n + 1) / 2 + n * (n - 1) / 2 = n * n
		// or = n * (n + 1)	= n * n + n;
		int cal = 0;
		bool odd = false;
		ans = sqrt(dis);
		while (1) {
			if (ans * ans >= dis) {
				odd = true;
				break;
			}
			else if (ans * (ans + 1) >= dis) {
				odd = false;
				break;
			}
			ans++;
		}
		if (odd)
			printf("%d\n", ans + ans - 1);
		else
			printf("%d\n", ans + ans);
	}
}


/*
1 1 (1)

2 2 (1, 1)

3 3
4 3 (1, 2, 1)

5 4
6 4 (1, 2, 2, 1)

7 5
8 5
9 5 (1, 2, 3, 2, 1)

10 6
11 6
12 6 (1, 2, 3, 3, 2, 1)

13 7
14
15
16 7 (1, 2, 3, 4, 3, 2, 1)

17 8
18
19
20 8 (1, 2, 3, 4, 4, 3, 2, 1)

21 9
22
23
24
25 9 (1, 2, 3, 4, 5, 4, 3, 2, 1)

20 10 (1~5, 5~1)

36 11 (1 ~ 6 ~ 1)

42 12 (1 ~6, 6 ~ 1)

*/