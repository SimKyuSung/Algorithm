/// 13913.¼û¹Ù²ÀÁú 4

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

#define endl '\n'

using namespace std;

const int MAX = 100001;
queue <int> q;
int check[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(check, -1, sizeof(check));

	int n, k, ans = 0, qSize = 1, nextSize;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << endl << n << endl;
		return 0;
	}

	q.push(n);
	check[n] = n;
	while (!q.empty()) {
		nextSize = 0;
		while (qSize--) {
			n = q.front();
			q.pop();
			if (n == k) {
				cout << ans << endl;
				vector <int> x;
				while (check[n] != n) {
					x.push_back(n);
					n = check[n];
				}
				x.push_back(n);
				while (!x.empty()) {
					cout << x.back() << ' ';
					x.pop_back();
				}
				cout << endl;
				return 0;
			}
			if (0 < n && check[n - 1] == -1) {
				check[n - 1] = n;
				q.push(n - 1);
				nextSize++;
			}
			if (n < 100000 && check[n + 1] == -1) {
				check[n + 1] = n;
				q.push(n + 1);
				nextSize++;
			}
			if (n * 2 < MAX && check[n * 2] == -1) {
				check[n * 2] = n;
				q.push(n * 2);
				nextSize++;
			}
		}
		qSize = nextSize;
		ans++;
	}
}