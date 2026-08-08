/// 2806. N-Queen

#include <iostream>
#include <memory.h>

using namespace std;

int n;
int c1[100];
int c2[200];
int c3[200];

int nQueen(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));

		cin >> n;

		cout << '#' << t << ' ' << nQueen(0) << '\n';
	}
}

int nQueen(int x) {
	if (x == n)
		return 1;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!c1[i] && !c2[x - i + n - 1] && !c3[x + i]) {
			c1[i] = c2[x - i + n - 1] = c3[x + i] = 1;
			ans += nQueen(x + 1);
			c1[i] = c2[x - i + n - 1] = c3[x + i] = 0;
		}
	}
	return ans;
}