/// 15685드래곤 커브

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//            동 북 서 남
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool c[101][101];
vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, d, g = 10;
	a.push_back(0);
	while (g--) {
		// 방향 입력
		for (int i = a.size() - 1; i >= 0; i--)
			a.push_back((a[i] + 1) % 4);
	}

	int n, ans = 0;
	cin >> n;
	for (int t = 0; t < n; t++) {
		cin >> x >> y >> d >> g;
		// 그리기
		c[y][x] = 1;
		for (int i = 0; i < (1 << g); i++) {
			int nextX = x + dx[(a[i] + d) % 4];
			int nextY = y + dy[(a[i] + d) % 4];
			if (0 <= nextX && nextX <= 100 && 0 <= nextY && nextY <= 100)
				c[nextY][nextX] = true;
			x = nextX;
			y = nextY;
		}
	}
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (c[i][j] && c[i + 1][j] && c[i][j + 1] && c[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans << '\n';
}

/*

시계방향으로 돌아가면서 무늬를 찍는다.

*/