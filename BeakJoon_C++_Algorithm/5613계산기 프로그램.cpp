/// 5613계산기 프로그램

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans, num;
	char op;
	cin >> ans;
	while (1) {
		cin >> op;
		if (op == '=') break;
		else {
			cin >> num;
			if (op == '+')	ans += num;
			else if (op == '-')	ans -= num;
			else if (op == '*')	ans *= num;
			else if (op == '/')	ans /= num;
		}
	}
	cout << ans;
}