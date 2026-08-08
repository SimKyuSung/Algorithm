/// 3273.두 수의 합

#include <iostream>

#define endl '\n'

using namespace std;

int a[100000];
bool dp[2000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]] = 1;
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (x > a[i] && dp[x - a[i]])
			ans++;
	}
	cout << (ans >> 1) << endl;

}