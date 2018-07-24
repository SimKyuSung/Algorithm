/// 2805. 농작물 수확하기

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

삼성 채점 시스템의 형편이 없음으로 
cin 또는 scanf로 통일을 해서 사용하여야 한다.

*/