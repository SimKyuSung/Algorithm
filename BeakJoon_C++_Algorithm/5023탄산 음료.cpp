/// 5032탄산 음료

#include <iostream>

using namespace std;

int main() {
	int e, f, c, ans = 0;
	cin >> e >> f >> c;
	e += f;
	while (e >= c) {
		f = e / c;
		ans += f;
		e %= c;
		e += f;
	}
	cout << ans;
}