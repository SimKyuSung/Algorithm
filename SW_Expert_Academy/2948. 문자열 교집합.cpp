#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, bool> a;
int main()
{
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		int n, m, ans = 0;
		string input;
		cin >> n >> m;
		while (n--) {
			cin >> input;
			a.insert({ input, true });
		}
		while (m--) {
			cin >> input;
			ans += a[input];
		}
		a.clear();
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 1;
}