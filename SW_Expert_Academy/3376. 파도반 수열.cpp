/// 3376. 파도반 수열

#include <iostream>

using namespace std;

size_t a[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	a[3] = 1;
	a[5] = 1;
	for (int i = 6; i < 110; i++)
		a[i] = a[i - 1] + a[i - 5];

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		cout << '#' << t << ' ' << a[n + 4] << '\n';
	}
}
/*

0 1 2 3 4 5 6 7 8 9 10 11 12 13
0 0 0 1 0 1 1 1 2 2 3  4  5  7  9 
      

*/