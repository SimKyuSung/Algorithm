/// 1986. 지그재그 숫자

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		long long n;
		cin >> n;

		if (n % 2)	n = n / 2 + 1;
		else		n = n / -2;

		cout << '#' << t << ' ' << n << '\n';
	}
}

/*
홀수항
1 3 5 7

짝수항 
-2 -4 -6
*/