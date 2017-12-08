/// 14730ÚºİÑËÎßãÑº (Small)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long c, k, ans = 0;

	cin >> n;	
	while (n--) {
		cin >> c >> k;
		ans += c * k;
	}
	cout << ans << "\n";
}