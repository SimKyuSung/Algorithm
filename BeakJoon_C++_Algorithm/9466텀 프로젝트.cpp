/// 9466ер га╥на╖ф╝

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int team[100000];
int a[100000];
bool ch[100000];

int teamMaker(int);
int arrCounter;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		memset(ch, false, sizeof(ch));
		for (int i = 0; i < n; i++) {
			cin >> team[i];
			team[i]--;
		}
		for (int i = 0; i < n; i++) {
			if (!ch[i]) {
				arrCounter = 0;
				ans += teamMaker(i);
			}
		}
		cout << n - ans << "\n";
	}
}

int teamMaker(int i) {
	if (ch[i]) {
		int ret = arrCounter;
		for (ret = 0; ret < arrCounter; ret++) {
			if (a[ret] == i)
				return arrCounter - ret;
		}
		return arrCounter - ret;
	}
	ch[i] = true;
	a[arrCounter++] = i;
	return teamMaker(team[i]);
}