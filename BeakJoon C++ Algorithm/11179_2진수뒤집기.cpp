///	11179_2����������

#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int counter = 0;
	int temp = n;
	int bitMask = 1;

	while (n) {
		n >>= 1;
		counter++;
	}
	for (int i = 0; i < counter; i++) {
		n <<= 1;
		n = n + (temp % 2);
		temp >>= 1;
	}
	printf("%d\n", n);
}

/*
����ϰ� ¥�¹�� �ƽôº�?
1101

*/