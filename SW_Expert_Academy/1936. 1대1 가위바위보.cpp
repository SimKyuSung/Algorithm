/// 1936. 1대1 가위바위보

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	a -= b;
	if (a == 1 || a == -2)
		cout << 'A';
	else
		cout << 'B';
}