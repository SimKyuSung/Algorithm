/// 2661좋은수열

#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> a;

bool solve(int);
bool check(int);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	solve(0);

	for (int i = 0; i < n; i++)
		cout << a[i];
}

bool solve(int x) {
	if (x == n) return true;
	// 1 ~ 3 까지 중에 1개 넣는다.
	for (int i = 1; i < 4; i++) {
		a[x] = i;
		if (check(x)) {
			if (solve(x + 1))
				return true;
		}
	}
	return false;
}

bool check(int x) {
	// i 개 비교
	for (int i = 1; i <= (x + 1) / 2; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (a[x - j] != a[x - j - i])
				flag = true;
		}
		if (!flag) return false;
	}
	return true;
}