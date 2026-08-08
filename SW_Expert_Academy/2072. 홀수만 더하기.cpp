/// 2072. 홀수만 더하기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int input, ans = 0;
		for (int i = 0; i < 10; i++) {
			cin >> input;
			if (input % 2)
				ans += input;
		}

		cout << '#' << t << ' ' << ans << '\n';

	}
}