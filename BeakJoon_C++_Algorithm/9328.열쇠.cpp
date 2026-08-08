/// 9328.¿­¼è

#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

struct Point {
	int y, x;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int h, w;
char building[102][102];
bool check[102][102];
bool key[128];

int bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		memset(building, '.', sizeof(building));
		memset(key, 0, sizeof(key));

		string k;

		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				cin >> building[i][j];
		}
		cin >> k;
		if (k[0] != '0') {
			for (int i = 0; i < k.size(); i++)
				key[k[i] - 'a' + 'A'] = 1;
		}
		for (int i = 'a'; i <= 'z'; i++)
			key[i] = 1;
		key['.'] = 1;
		key['$'] = 1;

		int ans = -1;
		while (ans == -1)
			ans = bfs();
		cout << ans << endl;
	}
}

int bfs() {
	memset(check, 0, sizeof(check));
	int ans = 0;
	queue <Point> q;
	q.push({ 0, 0 });
	check[0][0] = 1;
	
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (0 <= nx && nx <= w + 1 && 0 <= ny && ny <= h + 1 && !check[ny][nx]) {
				char &next = building[ny][nx];
				if (key[next]) {
					if ('a' <= next && next <= 'z') {
						if (key[next - 'a' + 'A'] == 0) {
							key[next - 'a' + 'A'] = 1;
							return -1;
						}
					}
					ans += next == '$';
					check[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}
	}
	return ans;
}