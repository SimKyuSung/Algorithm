/// 2047. �Ź� ������

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