/// 11557Yangjojang of The Year

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string name, ans = "";
		int d, maximum = -1;
		while (n--) {
			cin >> name >> d;
			if (d > maximum) {
				maximum = d;
				ans = name;
			}
		}
		cout << ans << endl;
	}
}