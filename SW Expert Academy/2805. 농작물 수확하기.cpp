/// 2805. ���۹� ��Ȯ�ϱ�

#include <iostream>

using namespace std;

int farm[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%1d", &farm[i][j]);

		int ans = 0;
		for (int i = 0; i <= n / 2; i++)
			for (int j = 0; j <= n / 2; j++)
				ans += farm[i + j][j + n / 2 - i];

		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
				ans += farm[i + 1 + j][j + n / 2 - i];

		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*

�Ｚ ä�� �ý����� ������ �������� 
cin �Ǵ� scanf�� ������ �ؼ� ����Ͽ��� �Ѵ�.

*/