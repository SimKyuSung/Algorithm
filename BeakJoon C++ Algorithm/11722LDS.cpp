#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

int N;
int A[1000];
int dpTable[1000];

int main()
{
	cin >> N;
	int ans = 0;
	memset(dpTable, 0, sizeof(dpTable));

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[i] < A[j])
				if (dpTable[j] < dpTable[i] + 1)
					dpTable[j] = dpTable[i] + 1;
	for (int i = 0; i < N; i++)
		ans = max(ans, dpTable[i]);
	printf("%d\n", ans + 1);
}