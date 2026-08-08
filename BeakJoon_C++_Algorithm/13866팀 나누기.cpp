/// 13866ÆÀ ³ª´©±â

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int team[4];
	for (int i = 0; i < 4; i++)
		cin >> team[i];
	cout << abs(team[0] + team[3] - team[1] - team[2]) << '\n';
}