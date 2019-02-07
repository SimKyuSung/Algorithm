/// 9252.LCS 2

#include <iostream>
#include <string>
#include <memory.h>

#define endl '\n'

using namespace std;

string a, b;
int ans = 0;
int ansIdx = 0;

int dp[1004];
int idx[1004][1004];

void printLCS(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(idx, -1, sizeof(idx));

	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		int tmpAns = 0;
		int tmpIdx = -2;

		for (int j = 0; j < b.size(); j++) {
			int tmp = tmpAns;
			int dx = tmpIdx;

			if (tmpAns < dp[j]) {
				tmpAns = dp[j];
				tmpIdx = j;
			}
			if (a[i] == b[j] && dp[j] < tmp + 1) {
				dp[j] = tmp + 1;
				idx[j][tmp] = dx;
			}
			if (ans < dp[j]) {
				ans = dp[j];
				ansIdx = j;
			}
		}
	}

	cout << ans << endl;
	if (ans > 0) {
		printLCS(ansIdx, ans - 1);
		cout << endl;
	}
}

void printLCS(int x, int n) {
	if (idx[x][n] > -1)
		printLCS(idx[x][n], n - 1);
	cout << b[x];
}