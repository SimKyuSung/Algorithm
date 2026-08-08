/// 15988.1, 2, 3 ¥ı«œ±‚ 3

#include <iostream>

#define endl '\n'

using namespace std;

const int MOD = 1000000009;
const int MAX_N = 1000001;
int dp[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_N; i++) 
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}

/*
0	1
1	1
2	1+1								2
3	1+1+1	1+2						2+1				3
4	1+1+1+1	1+1+2	1+2+1	1+3		2+1+1	2+2		3+1		<7>


*/