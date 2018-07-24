/// 4466. �ִ� ����ǥ �����

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, k, input, ans = 0;
		cin >> n >> k;
		priority_queue<int> pq;
		while (n--) {
			cin >> input;
			pq.push(input);
		}
		while (k--) {
			ans += pq.top();
			pq.pop();
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}