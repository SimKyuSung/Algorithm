// 5014StartLink

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/*
F 채고 높이
S start
G get in
U up go
D down go
*/

int f, s, g, u, d;
vector <bool> check(1000004, false);
queue < pair<int, int> > q;
void move(int, int);

int main()
{
	int ans = -1;
	cin >> f >> s >> g >> u >> d;
	q.push({ s, 0 });
	while (!q.empty()) {
		if (q.front().first == g) {
			ans = q.front().second;
			break;
		}
		move(q.front().first, q.front().second);
		q.pop();
	}
	if (ans != -1)	printf("%d\n", ans);
	else			printf("use the stairs\n");
}

void move(int x, int counter) {
	int up = x + u;
	int down = x - d;
	if (up < f + 1 && !check[up]) {
		check[up] = true;
		q.push({ up, counter + 1 });
	}
	if (down > 0 && !check[down]) {
		check[down] = true;
		q.push({ down, counter + 1 });
	}
}