// 5623Sum

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int ans[1004];
long long bigAns = 0;

int main()
{
	int n;	cin >> n;
	int input;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &input);
			ans[i] += input;
			bigAns += input;
		}
	bigAns >>= 1;
	if (n == 2) {
		printf("1 1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", (ans[i] - bigAns / (n - 1)) / (n - 2));

}