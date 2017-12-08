/// 1475¹æ ¹øÈ£

#include <iostream>
#include <algorithm>

using namespace std;

int cnt[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, ans = 0, m = 0;
	cin >> n;
	
	if (n == 0) ans = 1;
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}

	swap(cnt[6], cnt[8]);
	for (int i = 0; i < 8; i++)
		ans = max(ans, cnt[i]);

	if (ans < (cnt[8] + cnt[9] + 1) / 2)
		ans = (cnt[6] + cnt[9] + 1) / 2;

	cout << ans << endl;
}