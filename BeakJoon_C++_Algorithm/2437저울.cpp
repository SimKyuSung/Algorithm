/// 2437Àú¿ï

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> balance;

int main()
{
	long long n;	cin >> n;
	balance.resize(n);
	for (int i = 0; i < n; i++)
		cin >> balance[i];
	sort(balance.begin(), balance.end());

	if (balance[0] > 1) {
		cout << 1;
		return 0;
	}

	long long ans = balance[0];
	for (int i = 1; i < n; i++) {
		if (ans + 1 < balance[i])	break;
		else 						ans += balance[i];
	}
	cout << ans + 1;
}

/*

1 1 2 3 6 7 30

1

1 2

1 2 3 4

1 2 3 4 5 6 7

1 2 3 4 5 6 7 8 9 10 11 12 13

19
19

1
2
4
8
16
32

1 2 4 8

*/