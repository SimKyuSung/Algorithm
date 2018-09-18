/// 9019.DSLR

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <memory.h>

#define endl '\n'

using namespace std;

const int MAX = 10000;

string bfs(int, int);
int p[MAX];
char cmd[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << bfs(a, b) << endl;
	}
}

string bfs(int a, int b) {
	memset(p, -1, sizeof(p));

	queue<int> q;
	int next;
	q.push(a);
	p[a] = a;
	cmd[a] = 'x';

	while (!q.empty()) {
		a = q.front();
		q.pop();
		// D
		next = (a * 2) % MAX;
		if (p[next] == -1) {
			p[next] = a;
			cmd[next] = 'D';
			if (next == b)
				break;
			q.push(next);
		}
		// S
		next = (a + MAX - 1) % MAX;
		if (p[next] == -1) {
			p[next] = a;
			cmd[next] = 'S';
			if (next == b)
				break;
			q.push(next);
		}
		// L
		next = (a % 1000) * 10 + a / 1000;
		if (p[next] == -1) {
			p[next] = a;
			cmd[next] = 'L';
			if (next == b)
				break;
			q.push(next);
		}
		// R
		next = (a % 10) * 1000 + (a / 10);
		if (p[next] == -1) {
			p[next] = a;
			cmd[next] = 'R';
			if (next == b)
				break;
			q.push(next);
		}
	}

	string ans = "";
	while (p[next] != next) {
		ans = cmd[next] + ans;
		next = p[next];
	}
	return ans;
}