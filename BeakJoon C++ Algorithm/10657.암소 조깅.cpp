/// 10657.¾Ï¼Ò Á¶±ë

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector <pair<int, int> > cow;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	cow.resize(n);

	for (auto &c : cow)
		cin >> c.first >> c.second;
	sort(cow.begin(), cow.end());
	
	int decrease = cow.back().second;
	int ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (cow[i].second <= decrease) {
			decrease = cow[i].second;
			ans++;
		}
	}
	cout << ans << endl;
}