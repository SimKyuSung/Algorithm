/// 4676. 늘어지는 소리 만들기

#include <iostream>
#include <string>
#include <memory.h>

#define endl '\n'

using namespace std;

int a[20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string s;
		int h, index;
		memset(a, 0, sizeof(a));
		cin >> s >> h;
		while (h--) {
			cin >> index;
			a[index] ++;
		}

		cout << '#' << t << ' ';
		int i = 0;
		while (i < s.size()) {
			while (a[i]) {
				a[i]--;
				cout << '-';
			}
			cout << s[i++];
		}
		while (a[i]) {
			a[i]--;
			cout << '-';
		}
		cout << endl;
	}
}