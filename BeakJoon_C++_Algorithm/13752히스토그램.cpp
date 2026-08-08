/// 13752히스토그램

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		while (k--)
			cout << '=';
		cout << '\n';
	}
}