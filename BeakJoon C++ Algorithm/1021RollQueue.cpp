///1021RollQueue

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

deque <int> dq;
queue <int> order;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	int input, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		order.push(input);
	}
	for (int i = 0; i < n; i++)
		dq.push_back(i + 1);

	while (!order.empty()) {
		deque <int>::iterator iter;
		int counter = 0;

		for (iter = dq.begin(); iter != dq.end(); ++counter, ++iter)
			if (*iter == order.front())
				break;

		// 절반 보다 뒤에 있으면 3연산
		if (counter > dq.size() / 2) {
			while (dq.front() != order.front()) {
				ans++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
			order.pop();
		}
		else {	// 절반 보다 앞에 있으면 2연산
			while (dq.front() != order.front()) {
				ans++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
			order.pop();
		}
	}
	cout << ans << endl;
}