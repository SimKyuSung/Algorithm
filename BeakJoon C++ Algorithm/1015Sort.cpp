/// 1015��������

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int A[50];
int B[50];
int P[50];

int main()
{
	int N;		// <= 50
	cin >> N;

	// A <= 1000
	for (int i = 0; i < N; i++)
		cin >> A[i];
	memset(P, 0, sizeof(P));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < N; i++) {
		// �� ��° ������ ���
		for (int j = 0; j < N; j++)
			if (A[i] > A[j])	P[i]++;
		// B�� ����
		// 1. �ߺ� ó��
		while (B[P[i]] == A[i])
			P[i]++;
		// 2. ����
		B[P[i]] = A[i];

	}

	for (int i = 0; i < N; i++)
		printf("%d ", P[i]);

}
/*
ù° �ٿ� �迭 A�� ũ�� N�� �־�����.
��° �ٿ��� �迭 A�� ���Ұ� 0������ ���ʴ�� �־�����.
N�� 50���� �۰ų� ���� �ڿ����̰�, �迭�� ���Ҵ� 1,000���� �۰ų� ���� �ڿ����̴�.

1 ~ 1000 �߿��� �ߺ� ������ ���ڰ� ���´�.

2 3 1
1 2 3

0 1 2 3


*/