/// 3456. ���簢�� ���� ã��

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << '#' << t << ' ' << (a ^ b ^ c) << '\n';
	}
}