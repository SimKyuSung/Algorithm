/// 11062카드게임

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector <int> card;
vector <vector<int> > dp;

int x;
int select(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		card = vector <int>(n);
		dp = vector <vector <int> >(n, vector <int>(n, 0));
		x = n % 2;
		for (int i = 0; i < n; i++)
			cin >> card[i];
		cout << select(0, n - 1) << "\n";

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++)
		//		cout << dp[i][j] << " ";
		//	cout << endl;
		//}
	}
	return 0;
}

int select(int left, int right) {
	int &ret = dp[left][right];

	bool turn = (left + right + x) % 2;
	if (turn && left == right)
		return ret = card[left];
	else if (!turn && left == right)
		return 0;
	if (ret != 0)
		return ret;

	if (turn)	return ret = max(select(left + 1, right) + card[left], select(left, right - 1) + card[right]);
	else		return ret = min(select(left + 1, right), select(left, right - 1));
}