/// 11006남욱이의 닭장

#include <iostream>

using namespace std;

int main()
{
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		m *= 2;
		cout << m - n << ' ' << m / 2 - m + n << '\n';
	}
}