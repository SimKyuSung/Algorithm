/// 1015수열정렬

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
		// 몇 번째 수인지 출력
		for (int j = 0; j < N; j++)
			if (A[i] > A[j])	P[i]++;
		// B에 저장
		// 1. 중복 처리
		while (B[P[i]] == A[i])
			P[i]++;
		// 2. 저장
		B[P[i]] = A[i];

	}

	for (int i = 0; i < N; i++)
		printf("%d ", P[i]);

}
/*
첫째 줄에 배열 A의 크기 N이 주어진다.
둘째 줄에는 배열 A의 원소가 0번부터 차례대로 주어진다.
N은 50보다 작거나 같은 자연수이고, 배열의 원소는 1,000보다 작거나 같은 자연수이다.

1 ~ 1000 중에서 중복 가능한 숫자가 나온다.

2 3 1
1 2 3

0 1 2 3


*/