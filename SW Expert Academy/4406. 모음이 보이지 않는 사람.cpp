/// 4406. 모음이 보이지 않는 사람

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
		string s;
		cin >> s;

		cout << '#' << t << ' ';
		for (int i = 0; i < s.size(); i++) {
			char a = s[i];
			if (a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u')
				cout << a;
		}
		cout << '\n';
	}
}