/// 14501Επ»η

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> t;
vector <int> p;
vector <int> dpTable;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int n;
	cin >> n;
	t.resize(n);
	p.resize(n);
	dpTable.resize(n + 2, 0);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i + t[i] <= n) {
			for (int j = i + t[i]; j <= n; j++)
				dpTable[i] = max(dpTable[i], dpTable[j]);
			dpTable[i] += p[i];
			ans = max(ans, dpTable[i]);
		}
	}

	cout << ans;
}

/*

3	1	3	1	3	1	3
1	9	1	9	1	9	1
			9	0	9	0	


*/