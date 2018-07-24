/// 1289. 원재의 메모리 복구하기

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string m;
		cin >> m;

		int counter = 0;
		char mask = '0';
		for (int i = 0; i < m.size(); i++) {
			if (m[i] != mask) {
				counter++;
				mask = m[i];
			}
		}

		cout << '#' << t << ' ' << counter << '\n';
	}
}