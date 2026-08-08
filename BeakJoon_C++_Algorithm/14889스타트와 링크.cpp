/// 14889스타트와 링크

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int s[20][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector <bool> team(n, 1);
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			team[i] = 0;
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	}

	int ans = 100;
	do {
		int teamScore[2] = { 0, 0 };
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				if (team[i] == team[j])
					teamScore[team[i]] += s[i][j] + s[j][i];
		}
		ans = min(ans, abs(teamScore[0] - teamScore[1]));
		if (ans == 0)
			break;
	} while (next_permutation(team.begin(), team.end()));
	cout << ans << endl;
}