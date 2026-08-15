/// 2070. 큰 놈, 작은 놈, 같은 놈

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m;
		char ans;
		cin >> n >> m;
		ans = n > m ? '>' : (n < m ? '<' : '=');
		cout << '#' << t << ' ' << ans << '\n';
	}
}