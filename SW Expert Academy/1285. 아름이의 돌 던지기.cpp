/// 1285. 아름이의 돌 던지기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, i, mini = 100001, counter = 0;
		cin >> n;
		while (n--) {
			cin >> i;
			if (i < 0) i *= -1;
			if (i < mini) {
				counter = 1;
				mini = i;
			}
			else if (i == mini)
				counter++;
		}
		cout << '#' << t << ' ' << mini << ' '  << counter << '\n';
	}
}