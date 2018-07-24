/// 1983. 조교의 성적 매기기

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

pair <int, int> score[100];
string grade[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			score[i] = { a * -7 + b * -9 + c * -4, i + 1 };
		}
		sort(score, score + n);

		int counter;
		for (int i = 0; i < n; i++)
			if (score[i].second == k)
				counter = i;

		cout << '#' << t << ' ' << grade[counter / (n / 10)] << '\n';

	}
}