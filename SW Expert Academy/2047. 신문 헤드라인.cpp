/// 2047. 신문 헤드라인

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a')
			s[i] -= 'a' - 'A';
	}
	cout << s << '\n';
}