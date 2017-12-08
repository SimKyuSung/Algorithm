// 2745Base10

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string num;
	int base, ans = 0;
	cin >> num;
	cin >> base;
	for (int i = num.length() - 1; i >= 0; i--) {
		if (num[i] >= 'A')
			num[i] = num[i] - 'A' + 10;
		else
			num[i] -= '0';
		ans += num[i] * pow(base, num.length() - i - 1);
	}
	printf("%d\n", ans);
}