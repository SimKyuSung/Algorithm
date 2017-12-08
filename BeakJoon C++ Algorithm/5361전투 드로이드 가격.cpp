/// 5361전투 드로이드 가격

#include <iostream>

using namespace std;

double part[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed;
	cout.precision(2);

	int t;
	cin >> t;
	while (t--) {
		double ans = 0, input;

		for (int i = 0; i < 5; i++) {
			cin >> input;
			ans += input * part[i];
		}
		cout << '$' << ans << '\n';
	}

}