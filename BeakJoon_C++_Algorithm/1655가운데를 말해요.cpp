/// 1655가운데를 말해요

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector <int>, less<int>> left;
	priority_queue<int, vector <int>, greater<int>> right;

	int n, a, mid;
	cin >> n;
	cin >> mid;
	left.push(mid);
	cout << mid << "\n";

	for (int i = 1; i < n; i++) {
		cin >> a;
		if (a > mid)	right.push(a);
		else			left.push(a);

		if (left.size() < right.size()) {
			left.push(right.top());
			right.pop();
		}
		else if (left.size() > right.size() + 1) {
			right.push(left.top());
			left.pop();
		}
		mid = left.top();
		cout << mid << "\n";
	}
}

/*
1 2 3 4 5

mid

5 5 6 7 8

*/