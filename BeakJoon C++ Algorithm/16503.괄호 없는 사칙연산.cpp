/// 16503.괄호 없는 사칙연산

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int cal(int, char, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	char op[2];

	cin >> a >> op[0] >> b >> op[1] >> c;
	int ans1, ans2;
	ans1 = cal(cal(a, op[0], b), op[1], c);
	ans2 = cal(a, op[0], cal(b, op[1], c));

	cout << min(ans1, ans2) << endl;
	cout << max(ans1, ans2) << endl;
}
int cal(int a, char op, int b) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0;
	}
}