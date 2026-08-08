/// 1945. 간단한 소인수분해

#include <iostream>

using namespace std;

int p[5] = { 2, 3, 5, 7, 11 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		cout << '#' << t;
		for (int i = 0; i < 5; i++) {
			int output = 0;
			while (n % p[i] == 0) {
				n /= p[i];
				output++;
			}
			cout << ' ' << output;
		}
		cout << '\n';
	}
}