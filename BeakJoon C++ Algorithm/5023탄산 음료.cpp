/// 5032Åº»ê À½·á

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