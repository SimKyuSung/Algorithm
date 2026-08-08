/// 2029. 몫과 나머지 출력하기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int a, b;
		cin >> a >> b;

		cout << '#' << t << ' ' << a / b << ' ' << a % b << '\n';
	}
}