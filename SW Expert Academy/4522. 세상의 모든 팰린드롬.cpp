/// 4522. 세상의 모든 팰린드롬

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string p, ans = "Exist";
		cin >> p;
		int n = p.length();
		for (int i = 0; i < n / 2; i++) {
			if (p[i] != p[n - i - 1] && p[i] != '?' && p[n - i - 1] != '?')
				ans = "Not exist";
		}
		cout << '#' << t << ' '<< ans << endl;
	}
}