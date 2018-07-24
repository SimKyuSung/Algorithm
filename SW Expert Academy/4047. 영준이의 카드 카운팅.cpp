/// 4047. 영준이의 카드 카운팅

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int c[128];
int card[4][14];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	c['S'] = 0;
	c['D'] = 1;
	c['H'] = 2;
	c['C'] = 3;

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string s;
		bool ans = 1;
		memset(card, 0, sizeof(card));

		cin >> s;

		for (int i = 0; i < s.size() / 3; i++) {
			int x = c[s[i * 3]];
			int num = (s[i * 3 + 1] - '0') * 10 + s[i * 3 + 2] - '0' - 1;
			if (card[x][num])
				ans = 0;
			card[x][13]++;
			card[x][num] = 1;
		}
		cout << '#' << t;
		if (ans) {
			for (int i = 0; i < 4; i++)
				cout << ' ' << 13 - card[i][13];
		}
		else {
			cout << " ERROR";
		}
		cout << '\n';
	}
}