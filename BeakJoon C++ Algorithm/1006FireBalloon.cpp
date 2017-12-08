#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXX = 20009;

int n, w, E;
int c[2][100005];		// ��Ÿ��
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

		// ���� ó���� ���
		// [n]�� [0]���� �־� tmp ������ ���
		for (int i = 0; i < n; i++)	cin >> c[0][i];
		for (int i = 0; i < n; i++)	cin >> c[1][i];
		c[0][n] = c[0][0];
		c[1][n] = c[1][0];

		// algorithm sequence

		// -1. �� ���� ���� ����
		memset(dpTable, -1, sizeof(dpTable));
		ans = function3(n - 1);
		// ħ�������� 2���� �ϰ�� ó��
		if (n == 1) {
			printf("%d\n", ans);
			continue;
		}
		// 0. [0][0]��, [1][0]2�� ��� ���
		memset(dpTable, -1, sizeof(dpTable));
		if (c[0][n - 1] + c[0][0] <= w && c[1][n - 1] + c[1][0] <= w) {
			// index [0][0], [1][0]�� �̹� ��� ��
			c[0][0] = MAXX;
			c[1][0] = MAXX;

			ans = min(ans, function3(n - 2) + 2);

			// ����
			c[0][0] = c[0][n];
			c[1][0] = c[1][n];
		}

		// 1. [0][0]���� �մ� ���
		memset(dpTable, -1, sizeof(dpTable));
		if (c[0][n - 1] + c[0][0] <= w) {
			// index [0][0] ��� ����
			c[0][0] = MAXX;
			// 2���� ������ �Ҵ븦 �������� �Ǹ������� 0
			ans = min(ans, function2(n - 1) + 1);
			// ����
			c[0][0] = c[0][n];
		}

		// 2. [1][0]���� �մ� ���
		memset(dpTable, -1, sizeof(dpTable));
		if (c[1][n - 1] + c[1][0] <= w) {
			// index [1][0]�� ������� ���ϰ� ���� ����
			c[1][0] = MAXX;

			ans = min(ans, function1(n - 1) + 1);
			// ����
			c[1][0] = c[1][n];
		}

		printf("%d\n", ans);
	}
}

// index�� 1�� ���� ����
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
	// 0�� ��
	if (c[0][index] + c[0][index - 1] <= w)
		ref = min(ref, function2(index - 1) + 1);
	return ref;
}
// index�� 0�� ���� ����
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
	// 1�� ��
	if (c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function1(index - 1) + 1);
	return ref;
}

// index�� ���� ��� Ȱ�� ������.
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
	// ���Ʒ� ��
	if (c[0][index] + c[1][index] <= w)
		ref = min(ref, function3(index - 1) + 1);
	// 0�� ��
	if (c[0][index] + c[0][index - 1] <= w)
		ref = min(ref, function2(index - 1) + 2);
	// 1����
	if (c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function1(index - 1) + 2);
	// 0�� 1�� ��� ��
	if (c[0][index] + c[0][index - 1] <= w && c[1][index] + c[1][index - 1] <= w)
		ref = min(ref, function3(index - 2) + 2);
	return ref;
}

// make dpTable
/* �� �Ҵ�� 1���� �Ǵ� 2������ �ô´�.
* ���� dp�� ����Ͽ� ���踦 �� ���
* �� ������
* 11�������� ó�� ���� ����
* 10�������� ó�� ���� ����
* 01�������� ó�� ���� ����
* ����Ͽ� �ϸ� �ɰ� ����.
*/

//make edge
/*	������ ����� �Ұ�� ���� �˻�, �߰�, ������ ����� ���� ����. */