/// 1859. 백만 장자 프로젝트

#include <iostream>
#include <memory.h>

using namespace std;

int s[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];

		size_t sell = 0, m = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (m < s[i])
				m = s[i];
			else
				sell += (m - s[i]);
		}

		cout << '#' << t << ' ' << sell << '\n';

	}
}