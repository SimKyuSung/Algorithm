/// 2056. 연월일 달력

#include <iostream>
#include <iomanip>

using namespace std;

int lastDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, y, m, d;
		cin >> n;
		d = n % 100;
		n /= 100;
		m = n % 100;
		n /= 100;
		y = n;


		cout << '#' << t << ' ';
		if (d > lastDay[m])
			cout << -1 << '\n';
		else {
			cout << setw(4) << setfill('0') << y;
			cout << '/' << setw(2) << setfill('0') << m;
			cout << '/' << setw(2) << setfill('0') << d << '\n';
		}
	}
}