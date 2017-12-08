#include <iostream>

using namespace std;

int main()
{
	int N;
	int ans = 0;
	int d;
	cin >> N;
	// 등차수열을 만족하는 개수
	for (int i = N; i > 0; i--) {
		// 100미만은 모두 등차 수열
		if (i < 100)
			ans++;
		else {	// 각 자리 수의 차이를 비교
			d = (i / 100) - ((i / 10) % 10);
			if (d == (i / 10) % 10 - (i % 10))
				ans++;
		}
	}
	cout << ans << "\n";
}