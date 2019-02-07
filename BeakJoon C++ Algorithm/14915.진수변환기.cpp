/// 14915.진수변환기

#include <iostream>

#define endl '\n'

using namespace std;

int num[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m, n, counter = 0;
	cin >> m >> n;

	if (m == 0)
		cout << 0;
	while (m) {
		num[counter++] = m % n;
		m /= n;
	}
	while (counter--) {
		if (num[counter] > 9)
			cout << char('A' + num[counter] - 10);
		else
			cout << num[counter];
	}
	cout << endl;
}