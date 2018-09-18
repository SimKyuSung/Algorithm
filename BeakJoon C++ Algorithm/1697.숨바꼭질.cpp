/// 1697.¼û¹Ù²ÀÁú

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

const int MAX = 100001;
queue <int> q;
bool check[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, ans = 0, qSize = 1, nextSize;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << endl;
		return 0;
	}

	q.push(n);
	check[n] = 1;
	while (!q.empty()) {
		nextSize = 0;
		while (qSize--) {
			n = q.front();
			q.pop();
			if (n == k) {
				cout << ans << endl;
				return 0;
			}
			if (0 < n && !check[n - 1]) {
				check[n - 1] = 1;
				q.push(n - 1);
				nextSize++;
			}
			if (n < 100000 && !check[n + 1]) {
				check[n + 1] = 1;
				q.push(n + 1);
				nextSize++;
			}
			if (n * 2 < MAX && !check[n * 2]) {
				check[n * 2] = 1;
				q.push(n * 2);
				nextSize++;
			}
		}
		qSize = nextSize;
		ans++;
	}
}