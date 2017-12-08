/// 14494다이나믹이 뭐에요¿

#include <iostream>
#include <memory.h>

using namespace std;

const int mod = 1000000007;
int dpTable[1004][1004];

int function(int, int);

int main()
{
	memset(dpTable, -1, sizeof(dpTable));
	int n, m;	cin >> n >> m;
	for (int i = 0; i < n; i++) dpTable[i][0] = 1;
	for (int j = 0; j < m; j++) dpTable[0][j] = 1;
	//cout << function(n - 1, m - 1);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dpTable[i][j] = ((dpTable[i][j - 1] + dpTable[i - 1][j]) % mod + dpTable[i - 1][j - 1]) % mod;


	cout << dpTable[n - 1][m - 1];
}

int function(int n, int m) {
	int &ret = dpTable[n][m];
	if (ret != -1)	return ret;
	else			return ret = ((function(n, m - 1) + function(n - 1, m)) % mod + function(n - 1, m - 1)) % mod;
}
