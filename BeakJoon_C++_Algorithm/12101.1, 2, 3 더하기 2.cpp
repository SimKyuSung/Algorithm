/// 12101.1, 2, 3 ¥ı«œ±‚ 2

#include <iostream>

#define endl '\n'

using namespace std;

const int MAX_N = 12;
int dp[MAX_N];

void printPermutation(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_N; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int n, k;
	cin >> n >> k;
	if (k <= dp[n])
		printPermutation(n, k);
	else
		cout << -1 << endl;
}

void printPermutation(int n, int k) {
	//cout << n << ' ' << k << endl;
	if (n < 4 && dp[n] == k) {
		cout << n << "\n";
		return;
	}
	for (int i = 1; i < 4; i++) {
		k -= dp[n - i];
		if (k <= 0) {
			cout << i << '+';
			printPermutation(n - i, k + dp[n - i]);
			return;
		}
	}
	return;
}

/*
0	1
1	1														<1>
2	1+1								2						<2>
3	1+1+1	1+2						2+1				3		<4>
4	1+1+1+1	1+1+2	1+2+1	1+3		2+1+1	2+2		3+1		<7>
5	1 + <7>							2 + <4>			3 + <2>


*/