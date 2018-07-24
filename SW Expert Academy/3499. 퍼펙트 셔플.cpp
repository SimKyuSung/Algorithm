/// 3499. ∆€∆Â∆Æ º≈«√

#include <iostream>
#include <string>

using namespace std;

string line[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> line[i];

		cout << '#' << t;
		for (int i = 0; i < n / 2; i++) {
			cout << ' ' <<line[i];
			cout << ' ' << line[i + n / 2 + n % 2];
		}
		if (n % 2)
			cout << ' ' << line[n / 2];
		cout << '\n';
	}
}