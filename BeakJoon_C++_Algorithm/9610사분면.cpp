/// 9610»çºÐ¸é

#include <iostream>

using namespace std;

int n, x, y, q[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (x == 0 || y == 0)	q[0]++;
		else if (y > 0) {
			if (x > 0)	q[1]++;
			else		q[2]++;
		}
		else {
			if (x < 0)	q[3]++;
			else		q[4]++;
		}
	}
	cout << "Q1: " << q[1] << '\n';
	cout << "Q2: " << q[2] << '\n';
	cout << "Q3: " << q[3] << '\n';
	cout << "Q4: " << q[4] << '\n';
	cout << "AXIS: " << q[0] << '\n';
}