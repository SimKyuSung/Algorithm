/// 1486. 장훈이의 높은 선반

#include <iostream>
#include <memory.h>

#define endl '\n'

using namespace std;

int dp[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, b, h, ans = 0, sum = 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		cin >> n >> b;
		while (n--) {
			cin >> h;
			sum += h;
			for (int s = sum; s >= h; s--)
				dp[s] |= dp[s - h];
		}
		int i = b;
		while (1) {
			if (dp[i])
				break;
			i++;
		}
		cout << '#' << t << ' ' << i - b << endl;
	}
}