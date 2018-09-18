/// 1471.ªÁ≈¡µπ∏Æ±‚

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, ans;
int dp1[200001];
int dp2[200001];
int loopPoint;
int function(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		loopPoint = n + 1;
		ans = max(ans, function(i, 1));
	}
	cout << ans << endl;
}

int function(int x, int counter) {
	if (dp1[x] > 0)
		return dp1[x];
	if (dp2[x] > 0) {
		loopPoint = dp2[x];
		return counter - dp2[x];
	}
	dp2[x] = counter;
	int xx = x, next = 0;
	while (xx) {
		next += (xx % 10);
		xx /= 10;
	}

	dp1[x] = function((next + x - 1) % n + 1, counter + 1);
	if (counter < loopPoint)
		dp1[x]++;
	return dp1[x];
}