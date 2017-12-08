/// 13904°úÁ¦

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int> > dw;
vector <int> ans;

bool cmp(pair<int, int>, pair<int, int>);

int main()
{
	int n;

	cin >> n;

	dw.resize(n);
	ans.resize(1001, 0);

	for (int i = 0; i < n; i++)
		cin >> dw[i].first >> dw[i].second;

	sort(dw.begin(), dw.end(), cmp);

	for (int i = 0; i < n; i++) {
		//cout << dw[i].first << " " << dw[i].second << endl;
		int day = dw[i].first;
		while (ans[day]) day--;
		if (day != 0)
			ans[day] = dw[i].second;
	}
	int result = 0;
	for (int i = 1; i <= 1000; i++) {
		result += ans[i];
	}
	cout << result << endl;
}


bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) return true;
	else {
		if (a.second == b.second && a.first < b.first)
			return true;
		else
			return false;
	}
}
/*

7
4 60
4 40
1 20	x
2 50
3 30
4 10	x
6 5

4 60
2 50
4 40
3 30
1 20
4 10
6 5

1 40
2 40
3 40
4 40

*/