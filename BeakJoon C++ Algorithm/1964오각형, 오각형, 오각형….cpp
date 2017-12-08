/// 1964오각형, 오각형, 오각형…

#include <cstdio>

const int mod = 45678;

int main()
{
	int n;	scanf("%d", &n);
	int ans = 5;
	for (int i = 1; i < n; i++)
		ans = (ans + i * 3 + 4) % mod;
	printf("%d", ans);
}

/*
5

1 313 3 + 4  
2 424 6 + 4
3 535 9 + 4


*/