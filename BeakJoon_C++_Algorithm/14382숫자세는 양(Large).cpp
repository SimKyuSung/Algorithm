#include <cstdio>
int main()
{
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		if (n) {
			bool a[10] = { false };
			bool c = false;
			int i = 1;
			while (!c) {
				int k = n*i++;
				while (k) {
					a[k % 10] = 1;
					k /= 10;
				}
				c = true;
				for (auto b : a) if (!b) c = false;
			}
			printf("Case #%d: %d\n", t, n*(i - 1));
		}
		else	printf("Case #%d: INSOMNIA\n", t);
	}
}