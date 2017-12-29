/// 1013Contact

#include <iostream>
#include <string>

using namespace std;

string s;		// signal
bool f(int);	// function

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++)
			s[i] -= '0';
		if (f(0))	cout << "YES\n";
		else		cout << "NO\n";
	}
}

bool f(int n) {
	//for (int i = 0; i < n; i++)
	//	cout << char(s[i] + '0');
	//cout << endl;

	if (n == s.length()) return true;
	if (s[n] == 0) {
		if (n + 1 == s.length() || s[n + 1] == 0)
			return false;
		return f(n + 2);
	}
	else {
		int tmp = n + 1;
		while (tmp < s.length() && s[tmp] != 1)
			tmp++;
		// 0이 2개 이상 있었는지 판단. | tmp1이 마지막 이라면 뒤에 1이 없음으로 탈락
		if ((tmp < n + 3) || (tmp == s.length()))
			return false;

		while (tmp < s.length() && s[tmp] != 0)
			tmp++;

		bool ret = f(tmp);
		if (s[tmp - 2] == 1)
			ret |= f(tmp - 1);
		return ret;
	}
}