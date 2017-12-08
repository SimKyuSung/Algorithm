/// 14716Çö¼ö¸·

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int> > a(250, vector<int> (250));
vector <vector <bool> > ch(250, vector<bool>(250, false));

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	queue <pair <int, int> > q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !ch[i][j]) {
				ans++;
				ch[i][j] = true;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int d = 0; d < 8; d++) {
						int xx = x + dx[d];
						int yy = y + dy[d];
						if (0 <= xx && xx < m && 0 <= yy && yy < n && !ch[yy][xx] && a[yy][xx]) {
							q.push({ yy, xx });
							ch[yy][xx] = true;
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

