/// 13549.¼û¹Ù²ÀÁú 3

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
struct Point {
	int n, t;
};
queue <Point> q;
bool check[100001];

int main()
{
	int n, k, t = 0, next;
	cin >> n >> k;
	q.push({ n, t });
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		n = now.n;
		t = now.t;
		if (n == k) {
			cout << t << endl;
			break;
		}
		if (n * 2 < MAX && !check[n * 2]) {
			next = n * 2;
			q.push({ next, t });
			check[next] = 1;
		}

		if (0 < n && !check[n - 1]) {
			next = n - 1;
			check[next] = 1;
			q.push({ next, t + 1 });
		}
		if (n < 100000 && !check[n + 1]) {
			next = n + 1;
			check[next] = 1;
			q.push({ next, t + 1 });
		}
	}
}