/// SW Expert Academy

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, ans = 0;
		cin >> n;

		cout << '#' << t << ' ' << ans << endl;
	}
}