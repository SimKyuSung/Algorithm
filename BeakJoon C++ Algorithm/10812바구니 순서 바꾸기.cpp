/// 10812바구니 순서 바꾸기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> b;

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, m;
	cin >> n >> m;
	b.resize(n);
	for (int i = 0; i < n; i++) b[i] = i;
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		i--, k--;
		rotate(b.begin() + i, b.begin() + k, b.begin() + j);
	}
	for (int i = 0; i < n; i++)
		cout << b[i] + 1 << " ";
	cout << "\n";
}