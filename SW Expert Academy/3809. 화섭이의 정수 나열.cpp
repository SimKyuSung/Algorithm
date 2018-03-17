/// 3809. 화섭이의 정수 나열

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int num[1000];
bool c[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		size_t ans = 1000000;
		memset(c, 0, sizeof(c));
		
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> num[i];

		size_t ten = 1;
		for (int x = 0; x < 5; x++) {
			for (int i = 0; i < n - x; i++) {
				int tmp = 0;
				for (int j = i; j < x + 1 + i; j++) {
					tmp *= 10;
					tmp += num[j];
				}
				c[tmp] = true;
			}

			for (size_t i = 0; i < ten * 10; i++)
				if (!c[i])
					ans = min(ans, i);
			if (ans != 1000000)
				break;
			ten *= 10;
		}
		

		cout << '#' << t << ' ' << ans << '\n';
	}
}