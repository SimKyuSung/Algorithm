/// 2482색상환

#include <iostream>
#include <memory.h>

using namespace std;

const int MOD = 1000000003;
int color[1000][1001][2];

void findCase(int, int);
void dpInit(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	// n - 1번 선택안함
	dpInit(n, k);
	color[0][1][1] = 1;
	findCase(n, k);
	int ans = color[n - 1][k][0];
	// n - 1번 선택함
	dpInit(n, k);
	findCase(n, k);
	cout << (ans + color[n - 1][k][1]) % MOD << '\n';
}

void dpInit(int n, int k) {
	memset(color, -1, sizeof(color));
	for (int j = 0; j <= k; j++) {
		color[0][j][0] = 0;
		color[0][j][1] = 0;
	}
	for (int i = 0; i < n; i++) {
		color[i][0][0] = 1;
		color[i][0][1] = 1;
	}
}
void findCase(int n, int k) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k && j < n; j++) {
			color[i][j][0] = (color[i - 1][j][0] + color[i - 1][j][1]) % MOD;
			color[i][j][1] = color[i - 1][j - 1][0];
		}
	}
}