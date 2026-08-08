/// 4371. 항구에 들어오는 배

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, d, ans = 0;
		vector <int> ship;
		cin >> n >> d;
		while (--n) {
			cin >> d;
			d--;
			int i = 0;
			while(i < ship.size()) {
				if (d % ship[i] == 0)
					break;
				i++;
			}
			if (i == ship.size())
				ship.push_back(d);
		}
		ans = ship.size();
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*

3

3
0
2
3

5

0
6
9
12
18

3
1
500000000
999999999

*/