/// 14502연구소

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

// up, down, left, right
int moveX[4] = { 0, 0, -1, 1 };
int moveY[4] = { -1, 1, 0, 0 };

vector < vector <int> > s;
queue < pair<int, int> > q;

int main()
{
	cin >> n >> m;
	s.resize(n, vector <int>(m, 0));

	int maximum = 0;
	queue < pair<int, int> > tmp;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 0)
				maximum++;
			else if (s[i][j] == 2)
				tmp.push({ i, j });
		}
	}
	int ans = maximum;
	int x[3], y[3];
	for (int i = 0; i < n * m; i++) {
		x[0] = i % m;
		y[0] = i / m;
		if (s[y[0]][x[0]] != 0)	continue;
		s[y[0]][x[0]] = 1;
		
		for (int j = i + 1; j < n * m; j++) {
			x[1] = j % m;
			y[1] = j / m;
			if (s[y[1]][x[1]] != 0)	continue;
			s[y[1]][x[1]] = 1;
			
			for (int k = j + 1; k < n * m; k++) {
				x[2] = k % m;
				y[2] = k / m;
				if (s[y[2]][x[2]] != 0)	continue;
				s[y[2]][x[2]] = 1;
				int counter = 0;
				// 1. queue copy
				q = tmp;
				vector <pair <int, int> > rest;
				
				// 2. bfs
				while (!q.empty()) {
					// 2 - 1 큐 주변에 있는 값을 집어 삼키고 2로 바꿈
					for (int t = 0; t < 4; t++) {
						// 2 - 2 큐에 넣을 수 있는지 에러 체크
						int xx = q.front().second + moveX[t];
						int yy = q.front().first + moveY[t];
						if ((0 <= xx && xx < m && 0 <= yy && yy < n) && (s[yy][xx] == 0)) {
							rest.push_back({ yy, xx });
							s[yy][xx] = 2;
							q.push({ yy, xx });
							counter++;
						}
					}
					q.pop();
				}
				// cout << counter << endl;
				// 3. min counter
				ans = min(ans, counter);

				// 4, rest 값 다시 0으로
				for (int t = 0; t < rest.size(); t++)
					s[rest[t].first][rest[t].second] = 0;
				s[y[2]][x[2]] = 0;
			}
			s[y[1]][x[1]] = 0;
		}
		s[y[0]][x[0]] = 0;
	}

	cout << maximum - ans - 3 << endl;
}