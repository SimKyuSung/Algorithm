/// 2559¼ö¿­

#include <iostream>
#include <algorithm>

using namespace std;

int tmp[100000];
int sum[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, ans;
	cin >> n >> k;
	cin >> tmp[0];
	sum[0] = tmp[0];
	for (int i = 1; i < n; i++) {
		cin >> tmp[i];
		sum[i] += sum[i - 1] + tmp[i];
	}
	ans = sum[k - 1];
	for (int i = k; i < n; i++)
		ans = max(ans, sum[i] - sum[i - k]);
	cout << ans << '\n';
}