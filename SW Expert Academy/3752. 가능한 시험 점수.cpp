/// 3752. 가능한 시험 점수

#include <iostream>
#include <memory.h>

using namespace std;

bool dp[10001];

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		int n, input, sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> input;
			for (int j = sum; j >= 0; j--)
				if (dp[j])
					dp[j + input] = 1;
			sum += input;
		}

		int ans = 0;
		for (int i = 0; i <= sum; i++)
			if (dp[i])
				ans++;
	
		cout << '#' << t << ' ' << ans << '\n';
	}
}