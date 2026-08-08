/// 3975. 승률 비교하기

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		double a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		a1 /= a2;
		b1 /= b2;
		cout << '#' << t << ' ' << ((a1 == b1 ? "DRAW" : (a1 > b1 ? "ALICE" : "BOB"))) << '\n';
	}
}

/*

정수형으로 끝내고 싶으면, 최소공배수, 최대공약수 생각해서 풀기!

*/