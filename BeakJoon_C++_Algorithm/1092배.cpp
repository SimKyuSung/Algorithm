/// 1092배

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> crane;
vector <int> boxMove;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int n, m;
	cin >> n;
	crane.resize(n);
	boxMove.resize(n);
	for (int i = 0; i < n; i++) cin >> crane[i];
	sort(crane.begin(), crane.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int box;
		cin >> box;
		for (int i = 0; i < n; i++) {
			if (crane[i] >= box) {
				boxMove[i]++;
				break;
			}
			else if (box > crane.back()) {
				cout << -1;
				return 0;
			}
		}
	}
	
	// 최적화 시행
	int x = n;
	int maxSecond = max(m / x + bool(m - (m / x) * x), boxMove.back());
	for (int i = 0; i < n - 1; i++, x--) {
		maxSecond = max(m / x + bool(m - (m / x) * x), maxSecond);
		if (maxSecond < boxMove[i]) {
			boxMove[i + 1] += boxMove[i] - maxSecond;
			m -= maxSecond;
		}
		else m -= boxMove[i];
	}
	cout << maxSecond;
}

/*

3, 5 - > 1.66 = 2
4, 1, 0


10 0


*/