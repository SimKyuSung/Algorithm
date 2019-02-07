/// 16157.��α�

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>

#define endl '\n'

using namespace std;

int n, k = 3;


// ���� b ���� �����ؼ� 1 ~ Num�� �Ѱ��� ������ ����� �ּҰ�
// -> 1 ~ num ���¿��� b�� ����� �ּҰ�

//  left - right ������ c������ ����� ������
int dp[100][100][3];
bool check[100][100][3];
int dfs(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(dp, -1, sizeof(dp));
	// �Է�, r, g, b
	string line;
	cin >> n >> line;
	for (int i = 0; i < n; i++) {
		// ������ 1�� �϶� x -> x�� �ٲٴ� ���� 0�� �������� 1���� ����Ī
		int tmp = line[i] == 'R' ? 0 : (line[i] == 'G' ? 1 : 2);
		for (int c = 0; c < k; c++)
			dp[i][i][c] = (c != tmp);
	}

	int ans = 1e9;
	// ��� ������ c�� ���� ��
	for (int c = 0; c < k; c++)
		ans = min(ans, dfs(0, n - 1, c));
	cout << ans + 1 << endl;
}


int dfs(int left, int right, int num) {
	int &ret = dp[left][right][num];
	if (ret != -1)	return ret;
	ret = 1e9;

	// 2�� �������� �ּ�
	for (int i = left; i < right; i++)
		ret = min(ret, dfs(left, i, num) + dfs(i + 1, right, num));

	// left - right ������ �ٸ���ȣ�� �ٲ� (����ġ �ѹ� ����)
	if (!check[left][right][num]) {
		check[left][right][num] = 1;
		for (int c = 0; c < k; c++) {
			if (c != num)
				ret = min(ret, dfs(left, right, c) + 1);
		}
	}

	//cout << left << ' ' << right << ' ' << num <<  ' ' << ret << endl;
	return ret;
}

/*

1 2 3 2 1

0 5 1			0 5 2			0 5 3
1 1 1 1 1		2 2 2 2 2		3 3 3 3 3		
  2 2 2			1	3	1		1 2	  2 1	
	3

2��				3��				4��

*/

