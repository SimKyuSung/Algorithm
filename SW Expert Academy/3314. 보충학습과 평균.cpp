/// 3314. 보충학습과 평균

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n = 5, sum = 0, score;
		for (int i = 0; i < n; i++) {
			cin >> score;
			if (score < 40)
				score = 40;
			sum += score;
		}

		cout << '#' << t << ' ' << sum / 5 << '\n';
	}
}