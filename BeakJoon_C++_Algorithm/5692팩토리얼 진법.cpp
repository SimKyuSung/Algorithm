/// 5692팩토리얼 진법

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	while (1) {
		int n, ans = 0, tmp = 1, i = 2;
		scanf("%d", &n);
		if (n == 0)	break;
		while (n) {
			ans += (n % 10) * tmp;
			tmp *= i++;
			n /= 10;
		}
		printf("%d\n", ans);
	}
}