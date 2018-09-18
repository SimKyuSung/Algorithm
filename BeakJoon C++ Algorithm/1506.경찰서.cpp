/// 1506.경찰서

#include <iostream>
#include <bitset>
#include <memory.h>

#define endl '\n'

using namespace std;

int n;
int cost[100];
bitset <100> edge[100];
int p[100];
bool check[100];

bool dfs(int, int);
int getRoot(int);
void marge(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char buf[100];
	fread(buf, 1, 100, stdin);
	

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	for (int i = 0; i < n; i++) {
		p[i] = i;
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			edge[i][j] = (a == '1');
		}
	}

	for (int i = 0; i < n; i++) {
		if (p[i] == i) {
			memset(check, 0, sizeof(check));
			dfs(i, i);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] == i)
			ans += cost[i];
	}
	cout << ans << endl;
}
bool dfs(int a, int b) {
	check[a] = 1;
	bool ret = 0;
	if (edge[a][b]) {
		marge(a, b);
		ret = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i] && edge[a][i]) {
			if (dfs(i, b)) {
				edge[a] |= edge[i];
				marge(a, i);
				ret = 1;
			}
		}
	}
	return ret;
}
int getRoot(int a) {
	if (p[a] == a)
		return a;
	return p[a] = getRoot(p[a]);
}
void marge(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a == b)
		return;
	if (cost[a] > cost[b])
		p[a] = b;
	else
		p[b] = a;
}
/*

1. cycle이 있어야 도달 가능한 장소

00011
10000
00010
00100
01000

1 -> 4 -> 3
  -> 5 -> 2 -> 1
3 -> 4 -> 3

*/