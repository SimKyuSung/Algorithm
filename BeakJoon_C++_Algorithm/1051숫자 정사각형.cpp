/// 1051숫자 정사각형

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	int i, j;
	string line[50];
	cin >> n >> m;
	int ans = 1;
	for (i = 0; i < n; i++)
		cin >> line[i];
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 1; j++) {
			int ret = m - j > n - i ? n - i : m - j;
			char s = line[i][j];



			ans = max(ans, ret);
		}
	}
	cout << ans * ans;
}

int solve(int x, int y, string line[], int ret) {
	char s = line[y][x];
	// 1씩 줄여가면서 검색
	while (ret > 0) {
		if (s == line[y][x + ret] && s == line[y + ret][x] && s == line[y + ret][x + ret])
			return ret + 1;
		ret--;
	}
	return 1;
}


/*

3 5
42101
22100
22101

j, i = 0 1
s = 2
maxSize = 1;



*/