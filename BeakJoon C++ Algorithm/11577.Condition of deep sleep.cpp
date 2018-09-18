/// 11577.Condition of deep sleep

#include <iostream>
#include <bitset>
#include <queue>

#define endl '\n'

using namespace std;

bitset <100001> bulb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int onOFF;
		cin >> onOFF;
		bulb[i] = onOFF;
	}

	queue <int> q;
	for (int i = 0; i <= n - k; i++) {
		if (!q.empty() && q.front() <= i)
			q.pop();

		// 전구가 켜져 있음
		if ((q.size() + bulb[i]) % 2) {
			//cout << q.size() + bulb[i] << ' ' << i << endl;
			ans++;
			q.push(i + k);
		}
	}

	bool insomnia = 0;
	for (int i = n - k + 1; i < n; i++) {
		if (!q.empty() && q.front() <= i)
			q.pop();
		// 전구가 켜져 있음
		if ((q.size() + bulb[i]) % 2) {
			//cout << q.size() + bulb[i] << ' ' << i << endl;
			insomnia = 1;
			ans++;
			q.push(i + k);
		}
	}
	if (insomnia)
		cout << "Insomnia\n";
	else
		cout << ans << endl;
}