/// 13560축구 게임

#include <iostream>
#include <algorithm>

using namespace std;

int team[10001];
long long sum = 0;
long long sum2 = 0;

int main()
{
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> team[i];
	sort(team, team + n);

	bool ans = true;
	for (int i = 0; i < n; i++) {
		sum += i;
		sum2 += team[i];
		if (sum2 < sum) {
			ans = false;
			break;
		}
	}
	if (sum != sum2)
		ans = false;
	cout << (ans ? 1 : -1) << endl;
}
/*

2
0 1

3
0 1 2
1 1 1

4
0 1 2 3
0 2 2 2
1 1 1 3
1 1 2 2

5
0 1 2 3 4
0 2 2 2 4
0 2 2 3 3
1 1 1 3 4
1 1 2 2 4
1 1 2 3 3
1 2 2 2 3
2 2 2 2 2

6
0 1 2 3 4 5
0 2 2 2 4 5
0 2 2 3 3 5
0 2 2 3 4 4
0 2 3 3 3 4
0 3 3 3 3 3

1 1 1 3 4 5
1 1 2 2 4 5
1 1 2 3 3 5
1 1 2 3 4 4
1 1 3 3 3 4
1 2 



*/