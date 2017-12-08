// 2292Hexagon

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, ans = 1;
	int counter, hexa;
	cin >> n;
	counter = 2;
	hexa = 6;
	while (counter <= n) {
		counter += hexa;
		hexa += 6;
		ans++;
	}
	printf("%d\n", ans);
}

/*
1		1		2
2 ~ 7	2		8		6
8 ~ 19	3		20		12
20~ 37	4		38		18
38~ 61	5		62		24
92		30
128		36
*/