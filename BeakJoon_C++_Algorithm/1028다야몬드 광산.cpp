/// 1028다야몬드 광산

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > arr;
vector <vector <int> > dp1;
vector <vector <int> > dp2;

int main()
{
	int r, c, ans = 0;
	scanf("%d %d", &r, &c);
	arr.resize(r, vector<int>(c, 0));
	dp1.resize(r, vector<int>(c, 0));
	dp2.resize(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j]) ans = 1;
		}
	}

	for (int j = 0; j < c; j++)
		dp1[0][j] = dp2[0][j] = arr[0][j];
	for (int i = 0; i < r; i++) {
		dp1[i][0] = arr[i][0];
		dp2[i][c - 1] = arr[i][c - 1];
	}
	for (int i = 1; i < r; i++) {
		for (int j = 0; j < c - 1; j++)
			dp2[i][j] = (dp2[i - 1][j + 1] + 1) * arr[i][j];
		for (int j = 1; j < c; j++) {
			dp1[i][j] = (dp1[i - 1][j - 1] + 1) * arr[i][j];
			arr[i][j] = min(dp1[i][j], dp2[i][j]);
		}
	}

	for (int i = 2; i < r; i++)
		for (int j = 1; j < c - 1; j++)
			for (int k = ans; k < arr[i][j]; k++)
				if (k + 1 <= dp2[i - k][j - k] && k + 1 <= dp1[i - k][j + k])
					ans = max(ans, k + 1);

	printf("%d\n", ans);
}