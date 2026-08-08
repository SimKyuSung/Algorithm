/// 2805나무 자르기

#include <iostream>
#include <vector>

using namespace std;

vector <int> tree;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	tree.resize(n);
	for (int i = 0; i < n; i++)
		cin >> tree[i];

	int left = 1, right = 2e+9;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		// 가져가는 나무의 양
		long long total = 0;
		for (int i = 0; i < n; i++) {
			int x = tree[i] - mid;
			if (x > 0) total += x;
		}
		// 1. 모자름
		if (m > total)
			right = mid - 1;
		// 2. 너무 많이 자름
		else
			left = mid + 1;
		//cout << left << " " << right << endl;
	}
	cout << right;
}