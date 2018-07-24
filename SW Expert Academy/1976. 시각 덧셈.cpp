/// 1976. ½Ã°¢ µ¡¼À

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int h1, m1, h2, m2, h, m;
		cin >> h1 >> m1 >> h2 >> m2;
		
		m = m1 + m2;
		h = h1 + h2 + m / 60;

		m = m % 60;
		h = h % 12;
		h += (h == 0) * 12;

		cout << '#' << t << ' ' << h << ' ' << m << '\n';

	}
}

/*
 
 0 -> 12

*/