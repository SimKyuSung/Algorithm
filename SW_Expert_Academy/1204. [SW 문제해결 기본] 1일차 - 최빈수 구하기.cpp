/// 1204. [SW 문제해결 기본] 1일차 - 최빈수 구하기

#include <iostream>
#include <memory.h>

using namespace std;

int score[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	// cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(score, 0, sizeof(score));
		
		int n;
		string line;

		cin >> n;
		for (int i = 0; i < 1000; i++) {
			cin >> n;
			score[n]++;
		}

		int m = 0;
		for (int i = 0; i <= 100; i++) {
			if (m <= score[i]) {
				m = score[i];
				n = i;
			}
		}
		cout << '#' << t << ' ' << n << '\n';

	}
}