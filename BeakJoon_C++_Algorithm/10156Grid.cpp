// 10156Grid

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int k, n, m, ans;
	cin >> k >> n >> m;
	// 필요한돈, k * n
	// 엄마 한테 갈취하는 돈 = k * n - m
	ans = k * n - m;
	if (ans < 0)	printf("0\n");
	else			printf("%d\n", ans);
}