/// 16395.ÆÄ½ºÄ®ÀÇ »ï°¢Çü

#include <iostream>

#define endl '\n'

using namespace std;

int pt[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 31; i++) {
		pt[0][i] = 1;
		pt[i][i] = 1;
	}
	for (int i = 2; i < 31; i++) {
		for (int j = 1; j <= i; j++)
			pt[i][j] = pt[i - 1][j] + pt[i - 1][j - 1];
	}

	int n, k;
	cin >> n >> k;
	cout << pt[n][k] << endl;
}