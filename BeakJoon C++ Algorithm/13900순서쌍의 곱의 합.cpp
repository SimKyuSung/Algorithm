///13900¼ø¼­½ÖÀÇ °öÀÇ ÇÕ

#include <cstdio>

int arr[100000];

int main()
{
	int n;	scanf("%d", &n);
	unsigned long long sum = 0;
	unsigned long long ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += (unsigned long long)arr[i];
	}
	for (int i = 0; i < n; i++)
		ans += (unsigned long long)(sum - arr[i]) * arr[i];
	printf("%llu\n", ans / 2);
}