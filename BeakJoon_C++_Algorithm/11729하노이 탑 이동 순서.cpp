/// 11729하노이 탑 이동 순서

#include <cstdio>
#include <iostream>

using namespace std;

void hanoi(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	printf("%d\n", (1 << n) - 1);
	hanoi(n, 0, 2);
}

void hanoi(int n, int a, int b) {
	if (n == 1) {
		printf("%d %d\n", a + 1, b + 1);
		return;
	}
	// n이 2이상 일때
	int c = 3 - (a + b);
	// 1. a -> c
	hanoi(n - 1, a, c);
	// 2. a -> b
	printf("%d %d\n", a + 1, b + 1);
	// 3. c -> b
	hanoi(n - 1, c, b);
}

/*
1
1
13

2
3
12
13
23

3
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3

0 1 2

0 2 -> 1
0 1 -> 2
1 2 -> 0

*/