/// 14921용액 합성하기

#include <iostream>
#include <cmath>

using namespace std;

int a[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 210000000;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// left, right
	int l = 0, r = n - 1;
	while (l < r) {
		int x = a[l] + a[r];
		if (x < 0)  l++;
		else		r--;
		if (abs(ans) > abs(x))
			ans = x;
	}
	cout << ans;
}