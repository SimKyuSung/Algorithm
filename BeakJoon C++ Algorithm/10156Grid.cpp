// 10156Grid

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int k, n, m, ans;
	cin >> k >> n >> m;
	// �ʿ��ѵ�, k * n
	// ���� ���� �����ϴ� �� = k * n - m
	ans = k * n - m;
	if (ans < 0)	printf("0\n");
	else			printf("%d\n", ans);
}