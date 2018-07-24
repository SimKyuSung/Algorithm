/// 2001. �ĸ� ��ġ

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int fly[15][15];
int fly2[15][15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(fly2, 0, sizeof(fly2));

		int n, m, ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> fly[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				fly2[i][0] += fly[i][j];
			for (int j = 1; j <= n - m; j++)
				fly2[i][j] = fly2[i][j - 1] - fly[i][j - 1] + fly[i][j - 1 + m];
		}

		memset(fly, 0, sizeof(fly2));
		for (int j = 0; j <= n; j++) {
			for (int i = 0; i < m; i++)
				fly[0][j] += fly2[i][j];
			ans = max(ans, fly[0][j]);
			for (int i = 1; i <= n - m; i++) {
				fly[i][j] = fly[i - 1][j] -fly2[i - 1][j] + fly2[i - 1 + m][j];
				ans = max(ans, fly[i][j]);
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*

# ȿ�������� �ϴ� ���

���׸�Ʈ Ʈ������

2���� �迭�� ���׸�Ʈ Ʈ�� ���� ���
1) ������ �������� ���׸�Ʈ Ʈ�� ����
2) ���ϰ��� �ϴ� ������ ������ 

*/