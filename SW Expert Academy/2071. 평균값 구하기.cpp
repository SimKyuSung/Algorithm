/// 2071. 평균값 구하기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int x, sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> x;
			sum += x;
		}

		cout << '#' << t << ' ' << (sum * 10 + 50) / 100 << '\n';

	}
}