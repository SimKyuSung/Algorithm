/// 1984. 중간 평균값 구하기

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int cin, mini = 100000, maxi = 0, sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> cin;
			mini = min(mini, cin);
			maxi = max(maxi, cin);
			sum += cin;
		}
		sum -= mini + maxi;
		cout << '#' << t << ' ' << int(sum / 8.0 + 0.5) << '\n';

	}
}

/*
x * 10 / 80 = 
*/