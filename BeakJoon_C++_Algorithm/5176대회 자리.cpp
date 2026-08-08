/// 5176대회 자리

#include <iostream>
#include <memory.h>

using namespace std;

bool sit[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, p, m, a, ans;
	cin >> k;
	while (k--) {
		memset(sit, false, sizeof(sit));
		ans = 0;

		cin >> p >> m;
		while (p--) {
			cin >> a;
			if (sit[a]) ans++;
			sit[a] = true;
		}
		cout << ans << '\n';
	}
}