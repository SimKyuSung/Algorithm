/// 15633.Fan Death

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			ans += i;
	}
	cout << ans * 5 - 24 << endl;
}