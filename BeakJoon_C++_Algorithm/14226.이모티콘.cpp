/// 14226.이모티콘

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

struct State {
	int dis, cb;
};

int check[1004][1004];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(check, -1, sizeof(check));

	queue <State> q;
	q.push({ 1, 0 });
	check[1][0] = 0;

	int s;
	cin >> s;
	while (!q.empty()) {
		int dis = q.front().dis;
		int cb = q.front().cb;
		int t = check[dis][cb];
		q.pop();

		// 1. 클립보드 저장
		if (check[dis][dis] == -1) {
			check[dis][dis] = t + 1;
			q.push({ dis, dis });
		}
		// 2. 클립보드 붙여넣기
		if (dis + cb < 1004 && check[dis + cb][cb] == -1) {
			if (dis + cb == s) {
				cout << t + 1 << endl;
				return 0;
			}
			check[dis + cb][cb] = t + 1;
			q.push({ dis + cb, cb });
		}
		// 3.
		if (dis > 0 && check[dis - 1][cb] == -1) {
			if (dis - 1 == s) {
				cout << t + 1 << endl;
				return 0;
			}
			check[dis - 1][cb] = t + 1;
			q.push({ dis - 1, cb });
		}
	}
}