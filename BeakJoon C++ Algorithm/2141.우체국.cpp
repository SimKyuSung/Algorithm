/// 2285¿ìÃ¼±¹

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long long, long long> > xa;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	xa.resize(n);
	long long half = 0;
	long long peopleSum = 0;

	for (int i = 0; i < n; i++) {
		cin >> xa[i].first >> xa[i].second;
		peopleSum += xa[i].second;
	}
	half = (peopleSum + 1) / 2;
	peopleSum = 0;
	sort(xa.begin(), xa.end());
	for (int i = 0; i < n; i++) {
		peopleSum += xa[i].second;
		if (peopleSum >= half) {
			cout << xa[i].first << "\n";
			break;
		}
	}
}

/*

n = 100,000
| x[i] | <= 1,000,000,000
a[i] <= 1,000,000,000

3
1 3
2 5
3 3

5
-3 3
-1 1
0 2
3 7
6 1

n = 100000
xa[0]. = -1000000000

xa[i].f = 1000000000
xa[i].s = 1000000000

__int64
			  -9,223,372,036,854,775,808
			  ~ 9,223,372,036,854,775,807
ansRight = 19,999,800,000,000,000,000,000

*/