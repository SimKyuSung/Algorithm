/// 2879.코딩은 에쁘게

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <long long> x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	x.resize(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	long long move = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		long long hall;
		cin >> hall;

		// 목표보다 위에 있을때
		if (move + x[i] > hall) {
			// 모자란 움직임
			if (move < 0) {
				ans += move + x[i] - hall;
				move = hall - x[i];
			}
			// 거꾸로 움직임
			else {
				move = hall - x[i];
				if (move < 0)
					ans -= move;
			}
		}
		// 목표보다 아래 있을때
		else if (move + x[i] < hall) {
			// 모자란 움직임
			if (move > 0) {
				ans += hall - (x[i] + move);
				move = hall - x[i];
			}
			// 거꾸로 움직임
			else {
				move = hall - x[i];
				if (move > 0)
					ans += move;
			}
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}