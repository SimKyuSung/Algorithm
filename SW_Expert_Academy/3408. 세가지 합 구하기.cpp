/// 3408. 세가지 합 구하기

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		size_t n, s1, s2, s3;
		cin >> n;
		s1 = n * (n + 1) / 2;
		s2 = n * n;
		s3 = n * n + n;
		cout << '#' << t << ' ' << s1 << ' ' << s2 << ' ' << s3 << endl;
	}
}