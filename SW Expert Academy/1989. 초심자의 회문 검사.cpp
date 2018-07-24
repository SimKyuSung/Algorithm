/// 1989. 초심자의 회문 검사

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, p = 1;
		string s;
		cin >> s;

		n = s.size();

		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - 1 - i])
				p = 0;
		}

		cout << '#' << t << ' ' << p << '\n';
	}
}