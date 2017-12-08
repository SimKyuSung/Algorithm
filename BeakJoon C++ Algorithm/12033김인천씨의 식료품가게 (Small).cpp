/// 12033김인천씨의 식료품가게 (Small)

#include <cstdio>

int b_search(int, int, int*, int);

int main()
{
	int T;	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		int p[201];
		int v[201] = { 1 };
		int ans[101];
		n *= 2;
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);

		int j = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] != 0) {
				ans[j++] = p[i];
				v[b_search(i, n, p, p[i] / 3 * 4)] = 0;
			}
		}
		printf("Case #%d:", t);
		for (int i = 0; i < n / 2; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}

int b_search(int left, int right, int *p, int k) {
	// fine k and return index
	while (left < right) {
		int mid = (left + right) / 2;
		if (p[mid] == k)
			return mid;
		else if (p[mid] < k)
			left = mid;
		else
			right = mid + 1;
	}
	return -1;
}

/*

9 9 12 12 12 15 16 20

원가 12 12 16 20
할인 9  9  12 15

key 5
0 1 2 3 4 5 6
mid = 3


0 1 2  3  4  5  6  7
9 9 12 12 12 15 16 20
mid = 4



*/