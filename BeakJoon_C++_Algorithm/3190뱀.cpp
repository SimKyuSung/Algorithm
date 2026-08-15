/// 3190뱀

#include <iostream>
#include <vector>

using namespace std;

int m[102][102];
int se[100];
char d[100];

		//	  동 남 서 북
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 그녀는 배엠배엠배엠같은 여자!
	int n, k, l;
	cin >> n >> k;
	
	// 사과
	while (k--) {
		int r, c;
		cin >> r >> c;
		m[r][c] = 2;
	}

	// 벽
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
		// 출력
		//cout << seconds << endl;
		//for (int i = 0; i <= n + 1; i++) {
		//	for (int j = 0; j <= n + 1; j++) {
		//		if (m[i][j] == 0) cout << "  ";
		//		else if (m[i][j] == 1) cout << "□";
		//		else if (m[i][j] == 2) cout << "○";
		//		else if (m[i][j] == 3) cout << "■";
		//	}
		//	cout << endl;
		//}
		// 방향 설정
		if (se[cmdCounter] == seconds) {
			if (d[cmdCounter] == 'D') dir = (dir + 1) % 4;
			else					  dir = (dir + 3) % 4;
			cmdCounter++;
		}
		// 이동
		int x = s[0].second + dx[dir];
		int y = s[0].first + dy[dir];
		
		// 죽었는지 판별
		if (m[y][x] == 1 || m[y][x] == 3)
			break;
		// 사과 먹음
		else if (m[y][x] == 2)
			s.push_back(s.back());

		// 뱀 표시
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