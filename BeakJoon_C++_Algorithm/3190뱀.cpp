/// 3190¹ì

#include <iostream>
#include <vector>

using namespace std;

int m[102][102];
int se[100];
char d[100];

		//	  µ¿ ³² ¼­ ºÏ
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// ±×³à´Â ¹è¿¥¹è¿¥¹è¿¥°°Àº ¿©ÀÚ!
	int n, k, l;
	cin >> n >> k;
	
	// »ç°ú
	while (k--) {
		int r, c;
		cin >> r >> c;
		m[r][c] = 2;
	}

	// º®
	for (int i = 0; i <= n + 1; i++) {
		m[0][i] = 3;
		m[n + 1][i] = 3;
		m[i][0] = 3;
		m[i][n + 1] = 3;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
		cin >> se[i] >> d[i];

	vector <pair <int, int>> s(1, { 1, 1 });
	m[1][1] = 1;
	int seconds = 0;
	int cmdCounter = 0;
	int dir = 0;
	while (1) {
		// Ãâ·Â
		//cout << seconds << endl;
		//for (int i = 0; i <= n + 1; i++) {
		//	for (int j = 0; j <= n + 1; j++) {
		//		if (m[i][j] == 0) cout << "  ";
		//		else if (m[i][j] == 1) cout << "¡à";
		//		else if (m[i][j] == 2) cout << "¡Û";
		//		else if (m[i][j] == 3) cout << "¡á";
		//	}
		//	cout << endl;
		//}
		// ¹æÇâ ¼³Á¤
		if (se[cmdCounter] == seconds) {
			if (d[cmdCounter] == 'D') dir = (dir + 1) % 4;
			else					  dir = (dir + 3) % 4;
			cmdCounter++;
		}
		// ÀÌµ¿
		int x = s[0].second + dx[dir];
		int y = s[0].first + dy[dir];
		
		// Á×¾ú´ÂÁö ÆÇº°
		if (m[y][x] == 1 || m[y][x] == 3)
			break;
		// »ç°ú ¸ÔÀ½
		else if (m[y][x] == 2)
			s.push_back(s.back());

		// ¹ì Ç¥½Ã
		m[s.back().first][s.back().second] = 0;
		for (int i = s.size() - 1; i > 0; i--)
			s[i] = s[i - 1];
		s[0] = { y, x };
		m[s.back().first][s.back().second] = 1;
		m[y][x] = 1;
		seconds++;
	}
	cout << seconds + 1 << endl;
}

/*
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

9

6
11
1 2
1 3
1 4
1 5
1 6
2 1
2 2
2 3
2 4
2 5
2 6
5
5 D
6 D
11 D
12 D
17 D



*/