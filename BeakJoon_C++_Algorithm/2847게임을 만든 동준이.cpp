/// 2847게임을 만든 동준이

#include <iostream>

using namespace std;

int a[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] >= a[i + 1]) {
			ans += a[i] - (a[i + 1] - 1);
			a[i] = a[i + 1] - 1;
		}
	}
	cout << ans;
}