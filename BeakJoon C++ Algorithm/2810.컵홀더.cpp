/// 2810.дех╕╢У

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, cup = 1;
	string seat;
	cin >> n >> seat;
	for (int i = 0; i < n; i++) {
		if (seat[i] == 'L')
			i++;
		cup++;
	}
	if (cup > n)
		cup = n;
	cout << cup << endl;
}