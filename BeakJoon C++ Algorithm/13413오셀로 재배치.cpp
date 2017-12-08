/// 13413오셀로 재배치

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	string init, goal;

	cin >> t;
	while (t--) {
		// n <= 100000
		cin >> n >> init >> goal;
		int wc[2] = { 0, 0 };
		int ic = 0;
		for (int i = 0; i < n; i++) {
			if (init[i] != goal[i])
				ic++;
			wc[0] += init[i] == 'W';
			wc[1] += goal[i] == 'W';
		}
		ic += abs(wc[0] - wc[1]);
		cout << ic / 2 << '\n';
	}
}

/*
1. 뒤집거나
2. 옮기거나

*/