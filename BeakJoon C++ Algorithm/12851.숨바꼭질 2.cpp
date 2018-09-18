/// 12851.¼û¹Ù²ÀÁú 2

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

const int MAX = 100001;

struct Point {
	int n, t;
};
queue <Point> q;
bool check[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, t = 0;
	cin >> n >> k;

	int ansT = MAX, ansC = 0;

	q.push({ n, t });
	while (!q.empty()) {
		Point x = q.front();
		q.pop();
		n = x.n;
		t = x.t;
		check[n] = 1;
		if (t > ansT)
			break;
		if (n == k) {
			ansT = t;
			ansC++;
		}
		if (n * 2 < MAX && !check[n * 2])
			q.push({ n * 2, t + 1 });
		if (0 < n && !check[n - 1])
			q.push({ n - 1, t + 1 });
		if (n < 100000 && !check[n + 1])
			q.push({ n + 1, t + 1 });
	}
	cout << ansT << endl << ansC << endl;
}