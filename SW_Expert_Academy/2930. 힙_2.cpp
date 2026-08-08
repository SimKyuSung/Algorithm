/// 2930. Èü_2

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, cmd, x;
		priority_queue<int> pq;
		cin >> n;
		cout << '#' << t;
		while (n--) {
			cin >> cmd;
			if (cmd == 1) {
				cin >> x;
				pq.push(x);
			}
			else {
				if (pq.empty()) {
					cout << " -1";
				}
				else {
					cout << ' ' << pq.top();
					pq.pop();
				}
			}
		}
		cout <<endl;
	}
}