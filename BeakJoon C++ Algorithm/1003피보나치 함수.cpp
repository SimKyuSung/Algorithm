/// 1003피보나치 함수

#include <cstdio>

void function(int n);
int f[2][41];

int main()
{
	int t, n;
	f[0][0] = 1;
	f[1][0] = 0;
	f[0][1] = 0;
	f[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		f[0][i] = f[0][i - 2] + f[0][i - 1];
		f[1][i] = f[1][i - 2] + f[1][i - 1];
	}

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		printf("%d %d\n", f[0][n], f[1][n]);
	}
	return 0;
}

/*

0 -> 1 0
1 -> 0 1
2 -> 1 1
3 -> 1 2
4 -> 2 3
5 -> 3 5

*/