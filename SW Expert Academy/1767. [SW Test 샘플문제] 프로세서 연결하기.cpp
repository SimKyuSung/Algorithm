/// 1767. [SW Test ���ù���] ���μ��� �����ϱ�

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool cell[12][12];
// 0 ����, 1 ����
int dp[12][12][2];

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(dp, 0, sizeof(dp));

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> cell[i][j];

		

		cout << '#' << t << ' ' << '\n';

	}
}