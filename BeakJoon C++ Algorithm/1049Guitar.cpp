/// 1049Guitar

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// n < 100, m < 50
	int n, m;	cin >> n >> m;
	int ans;

	int minUnit6 = 1000, minPiece = 1000;
	int unit6, piece;
	for (int i = 0; i < m; i++) {
		cin >> unit6 >> piece;
		minUnit6 = min(minUnit6, unit6);
		minPiece = min(minPiece, piece);
	}

	if (minUnit6 == 0 || minPiece == 0)		ans = 0;
	else if (minUnit6 >= minPiece * 6)		ans = minPiece * n;
	else	ans = min(((n / 6) + 1) * minUnit6, (n / 6) * minUnit6 + minPiece * (n % 6));
	cout << ans;
}