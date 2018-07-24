/// 1970. 쉬운 거스름돈

#include <iostream>

using namespace std;

int money[8] = { 50000, 10000, 5000, 1000, 500, 100, 50 , 10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		
		cout << '#' << t << '\n';
		for (int i = 0; i < 8; i++) {
			cout << n / money[i] << ' ';
			n = n % money[i];
		}
		cout << '\n';
	}
}