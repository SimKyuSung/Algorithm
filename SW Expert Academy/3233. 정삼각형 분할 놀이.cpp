/// 3233. 정삼각형 분할 놀이

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		size_t a, b, n;
		cin >> a >> b;
		n = a / b;
		cout << '#' << t << ' ' << n * n << '\n';
	}
}