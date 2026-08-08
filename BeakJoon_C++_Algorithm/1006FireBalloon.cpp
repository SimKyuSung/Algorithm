#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXX = 20009;

int n, w, E;
int c[2][100005];		// 원타콘
						/*
						0 = 00
						1 = 01
						2 = 10
						3 = 11
						*/
int dpTable[4][100005];

int function1(int);
int function2(int);
int function3(int);

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		// n <= 10000
		int ans = MAXX;
		// input sequence
		cin >> n >> w;

		// 원형 처리의 경우
		// [n]에 [0]값을 넣어 tmp 변수로 사용
		for (int i = 0; i < n; i++)	cin >> c[0][i];
		for (int i = 0; i < n; i++)	cin >> c[1][i];
		c[0][n] = c[0][0];
		c[1][n] = c[1][0];

		// algorithm sequence

		// -1. 끝 점을 잇지 않음
		memset(dpTable, -1, sizeof(dpTable));
		ans = function3(n - 1);
		// 침투구역이 2군대 일경우 처리
		if (n == 1) {
			printf("%d\n", ans);
			continue;
		}
		// 0. [0][0]번, [1][0]2개 모두 사용
		memset(dpTable, -1, sizeof(dpTable));
		if (c[0][n - 1] + c[0][0] <= w && c[1][n - 1] + c[1][0] <= w) {
			// index [0][0], [1][0]을 이미 사용 함
			c[0][0] = MAXX;
			c[1][0] = MAXX;

			ans = min(ans, function3(n - 2) + 2);

			// 해제
			c[0][0] = c[0][n];
			c[1][0] = c[1][n];
		}

		// 1. [0][0]번과 잇는 경우
		memset(dpTable, -1, sizeof(dpTable));
		if (c[0][n - 1] + c[0][0] <= w) {
			// index [0][0] 사용 안함
			c[0][0] = MAXX;
			// 2개에 구역에 소대를 보내지만 맨마지막에 0
			ans = min(ans, function2(n - 1) + 1);
			// 해제
			c[0][0] = c[0][n];
		}

		// 2. [1][0]번과 잇는 경우
		memset(dpTable, -1, sizeof(dpTable));
		if (c[1][n - 1] + c[1][0] <= w) {
			// index [1][0]을 사용하지 못하게 막아 놓음
			c[1][0] = MAXX;

			ans = min(ans, function1(n - 1) + 1);
			// 해제
			c[1][0] = c[1][n];
		}

		printf("%d\n", ans);
	}
}

// index의 1번 점은 못씀
int function1(int index) {
	if (index == 0) {
		if (c[0][index] == MAXX)
			return 0;
		return 1;
	}
	int &ref = dpTable[1][index];
	if (ref != -1)
		return ref;
	ref = function3(index - 1) + 1;
	// 0층 합
	if (c[0][index] + c[0][index - 1] <= w)
		ref = min(ref, function2(index - 1) + 1);
	return ref;
}
// index의 0번 점은 못씀
int function2(int index) {
	if (index == 0) {
		if (c[1][index] == MAXX)
			return 0;
		return 1;
	}

	int &ref = dpTable[2][index];
	if (ref != -1)
		return ref;
	ref = function3(index - 1) + 1;
	// 1층 합
	if (c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function1(index - 1) + 1);
	return ref;
}

// index의 두점 모두 활용 가능함.
int function3(int index) {
	if (index < 0)
		return 0;
	if (index == 0) {
		if (c[0][0] == MAXX && c[1][0] == MAXX)
			return 0;
		if (c[0][0] == MAXX || c[1][0] == MAXX)
			return 1;
		if (c[0][0] + c[1][0] <= w)
			return 1;
		else
			return 2;
	}
	int &ref = dpTable[0][index];
	if (ref != -1)
		return ref;
	ref = function3(index - 1) + 2;
	// 위아래 합
	if (c[0][index] + c[1][index] <= w)
		ref = min(ref, function3(index - 1) + 1);
	// 0층 합
	if (c[0][index] + c[0][index - 1] <= w)
		ref = min(ref, function2(index - 1) + 2);
	// 1층합
	if (c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function1(index - 1) + 2);
	// 0층 1층 모두 합
	if (c[0][index] + c[0][index - 1] <= w && c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function3(index - 2) + 2);
	return ref;
}

// make dpTable
/* 각 소대는 1구격 또는 2구역을 맡는다.
* 만약 dp를 사용하여 설계를 할 경우
* 그 구역이
* 11구역으로 처리 가능 한지
* 10구역으로 처리 가능 한지
* 01구역으로 처리 가능 한지
* 계산하여 하면 될거 같다.
*/

//make edge
/*	엣지를 만들어 할경우 엣지 검색, 추가, 삭제에 비용이 많이 들어간다. */