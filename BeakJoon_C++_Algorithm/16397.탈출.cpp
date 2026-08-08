/// 16397.≈ª√‚

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

bool check[100000];
queue <int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, t, g, ans = 0;
	cin >> n >> t >> g;
	if (n == g) {
		cout << 0 << endl;
		return 0;
	}

	int qSize;
	check[n] = 1;
	q.push(n);
	while (!q.empty() && t--) {

		ans++;
		qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int now = q.front();
			q.pop();
			now++;
			if (0 <= now && now < 100000) {
				if (!check[now]) {
					q.push(now);
					check[now] = 1;
					if (now == g) {
						cout << ans << endl;
						return 0;
					}
				}
			}

			now--;
			int x = now * 2;
			int ten = 1;
			while (x > 9) {
				ten *= 10;
				x /= 10;
			}

			now = now << 1;
			if (now >= 100000)
				continue;
			now -= ten;
			if (0 <= now && now < 100000) {
				if (!check[now]) {
					q.push(now);
					check[now] = 1;
					if (now == g) {
						cout << ans << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "ANG" << endl;
}