/// 15989.1, 2, 3 ¥ı«œ±‚ 4

#include <iostream>

#define endl '\n'

using namespace std;

const int MOD = 1000000009;
const int MAX_N = 10001;
int dp[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for (int i = 4; i < MAX_N; i++)
		dp[i] = 1 + (i >> 1) + dp[i - 3];
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
1	1																<1>

2	1+1				2												<2>		2
	1				*
			

3	1+1+1			2+1							3					<3>		3
												*

4	1+1+1+1			2+1+1 2+2					3+1					<4>		
					*			

5	1+1+1+1+1		2+1+1+1	2+2+1				3+1+1 3+2			<5>		2
	1				2							2

6	1+1+1+1+1+1		2+1+1+1+1 2+2+1+1	2+2+2	3+1+1+1	3+2+1 3+3	<7>		2	3
	1				3							3
												1

7	1				3							3+1+1+1+1	3+2+1+1 3+3+1	<8>
												3+2+2
												(4)

8	1				4							5
9	1				4							7
10	1				5							8

*/