/// 2251.물통

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int ABC[3];
struct State {
	int abc[3];
	int checker() {
		return abc[2] * 201 * 201 + abc[1] * 201 + abc[0];
	}
};
// 201 * 201 * 201
bool check[8120601];
bool ans[201];
queue <State> q;
void qPush(State, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	State now;
	cin >> ABC[2] >> ABC[1] >> ABC[0];
	
	now.abc[2] = 0;
	now.abc[1] = 0;
	now.abc[0] = ABC[0];
	q.push(now);
	check[now.checker()] = 1;
	
	while (!q.empty()) {
		now = q.front();
		q.pop();
		//cout << now.abc[2] << now.abc[1] << now.abc[0] << endl;
		if (now.abc[2] == 0)
			ans[now.abc[0]] = 1;
		qPush(now, 0, 1);
		qPush(now, 0, 2);
		qPush(now, 1, 0);
		qPush(now, 1, 2);
		qPush(now, 2, 0);
		qPush(now, 2, 1);
	}

	for (int i = 0; i < 201; i++)
		if (ans[i])
			cout << i << ' ';
	cout << endl;

}

// b -> a 로 담기
void qPush(State next, int a, int b) {
	next.abc[a] += next.abc[b];
	next.abc[b] = 0;
	if (next.abc[a] > ABC[a]) {
		next.abc[b] += next.abc[a] - ABC[a];
		next.abc[a] = ABC[a];
	}
	if (!check[next.checker()]) {
		check[next.checker()] = 1;
		q.push(next);
	}
}

/*
상대를 가득 채우거나, 내가 0이 되면 끝
*/