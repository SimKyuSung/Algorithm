/// 11501.аж╫д

#include <iostream>

#define endl '\n'

using namespace std;

int stock[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> stock[i];

		size_t ans = 0, maxStock = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (stock[i] > maxStock)
				maxStock = stock[i];
			else if (stock[i] < maxStock) {
				ans += maxStock - stock[i];
			}
		}
		cout << ans << endl;

	}

}