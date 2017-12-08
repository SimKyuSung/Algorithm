/// 11653소인수 분해

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 2;
	while (n != 1) {
		while (n % ans == 0) {
			cout << ans << "\n";
			n /= ans;
		}
		ans++;
	}
}