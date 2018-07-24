/// 3307. 최장 증가 부분 수열

#include <iostream>

#define endl '\n'

using namespace std;

int dp[1004];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, input, ans = 1;
		cin >> n >> dp[0];
		while(--n) {
			cin >> input;
			if (input >= dp[ans - 1]) {
				dp[ans] = input;
				ans++;
			}
			else {
				int l = 0, r = ans - 1;
				while (l < r) {
					int mid = (l + r) / 2;
					if (dp[mid] >= input)
						r = mid;
					else
						l = mid + 1;
				}
				dp[l] = input;
			}
			//for (int i = 0; i < ans; i++)
			//	cout << dp[i] << ' ';
			//cout << endl;
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}

/*
	dp
4	4
2	2
3	2 3
1	1 3
5	1 3 5
6	1 3 5 6

4	4
2	2
4	2 4
1	1 4
2	1 2
3	1 2 3

        3        
0 1 2 3 4 5 6 7 8

1 3 2 5 4

0 1
1 3

*/