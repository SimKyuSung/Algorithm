/// 10448.유레카 이론

#include <iostream>

#define endl '\n'

using namespace std;

bool dp[1004][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 1
	int x = 1;
	for (int i = 2; x <= 1000; i++) {
		dp[x][0] = 1;
		x += i;
	}

	// 2
	for (int i = 1; i <= 1000; i++) {
		if (dp[i][0]) {
			for (int j = i; j + i <= 1000; j++) {
				if (dp[j][0])
					dp[i + j][1] = 1;
			}
		}
	}
	// 3
	for (int i = 1; i <= 1000; i++) {
		if (dp[i][0]) {
			for (int j = i; j + i <= 1000; j++) {
				if (dp[j][1])
					dp[i + j][2] = 1;
			}
		}
	}

	int t, k;
	cin >> t;
	while (t--) {
		cin >> k;
		cout << dp[k][2] << endl;
	}
}

/*
1 3 6 10 15 21 28 36 45 55

0 = 0
1 = 1
2 = 1 + 1
3 = 3 / 1 + 1 + 1 = ture;
4 = 1 + 3
5 = 1 + 1 + 3
6 = 6 / 3 + 3
7 = 1 + 3 + 3
8 = 

1 + 1
	3
	6
	10
	15
	21


*/