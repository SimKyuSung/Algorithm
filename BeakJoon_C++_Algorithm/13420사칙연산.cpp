/// 13420사칙연산

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--) {
		long long a, b, x, y;
		char op, eq;
		cin >> a >> op >> b >> eq >> x;
		switch (op) {
		case '+':
			y = a + b;
			break;
		case '-':
			y = a - b;
			break;
		case '*':
			y = a * b;
			break;
		case '/':
			y = a / b;
			break;
		default:
			break;
		}
		if (x == y) cout << "correct\n";
		else		cout << "wrong answer\n";
	}
}