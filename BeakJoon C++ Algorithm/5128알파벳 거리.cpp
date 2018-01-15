// 5128¾ËÆÄºª °Å¸®

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--) {
		string x, y;
		cin >> x >> y;
		cout << "Distances:";
		for (int i = 0; i < x.length(); i++) {
			int ans = y[i] - x[i];
			if (ans < 0) ans += 26;
			cout << " " << ans;
		}
		cout << '\n';
	}
}