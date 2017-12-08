/// 1080행렬

#include <cstdio>
#include <memory.h>

int main()
{
	int n, m;
	char input[51];
	short int a[50][50];
	short int b[50][50];
	
	int counter = 0;
	int ans = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		for (int j = 0; j < m; j++)
			a[i][j] = input[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		for (int j = 0; j < m; j++)
			b[i][j] = input[j] - '0';
	}
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {

			if (a[i][j] != b[i][j]) {
				for (int y = i; y < i + 3; y++)
					for (int x = j; x < j + 3; x++)
						a[y][x] ^= 1;
				counter++;
			}

		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j])
				ans++;

	if (ans)
		printf("-1\n");
	else
		printf("%d\n", counter);
}
/*
모든 경우의 수 체크 해보기

[50][50] 의 경우

답은 항상
48 * 48 = 2304 미만이다.

뒤집기 어케 하지...
???!!


*/