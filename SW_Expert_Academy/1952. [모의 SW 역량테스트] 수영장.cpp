/// 1952. [모의 SW 역량테스트] 수영장

#include <iostream>


#define endl '\n'

using namespace std;

// year, moon3, month, day;
// 12	 3		1	   day * const[3]
int cost[4];
int day[12];
int dp[12];
int MIN(int a, int b) { return a > b ? b : a; }
int solve(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int ans = 0, c = 4;
		while (c--)
			cin >> cost[c];
		for (int i = 0; i < 12; i++) {
			cin >> day[i];
			dp[i] = 9999;
		}

		cout << '#' << t << ' ' << solve(0) << endl;
		//for (int i = 0; i < 12; i++)
		//	cout << dp[i] << ' ';
		//cout << endl;
	}
}

int solve(int month) {
	if (month >= 12)
		return 0;

	int &ret = dp[month];
	if (ret != 9999)
		return ret;
	if (month == 0)
		ret = MIN(ret, cost[0]);
	ret = MIN(ret, solve(month + 3) + cost[1]);
	ret = MIN(ret, solve(month + 1) + MIN(cost[2], cost[3] * day[month]));
	return ret;
}
/*



*/