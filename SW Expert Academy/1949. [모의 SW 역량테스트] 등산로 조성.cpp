/// 1949. [모의 SW 역량테스트] 등산로 조성

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int m[8][8];
int dp[8][8];


int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 , 0 };

vector < pair <int, int> > peek;

int deepWay(int, int);

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int k, peekLvl = 0;
		peek.clear();

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				peekLvl = max(peekLvl, m[i][j]);
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (peekLvl == m[i][j])
					peek.push_back({ i, j });
		}

		int ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int s = 0; s < peek.size(); s++)
			ans = max(ans, deepWay(peek[s].first, peek[s].second));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int f = 1; f <= k; f++) {
					m[i][j] -= f;
					for (int s = 0; s < peek.size(); s++) {
						memset(dp, 0, sizeof(dp));
						ans = max(ans, deepWay(peek[s].first, peek[s].second));
						//if (ans == 11) {
						//	cout << i << ' ' << j << ' ' << f << ' ' << s << endl;
						//	int tmp;
						//	cin >> tmp;
						//}
					}
					m[i][j] += f;
				}
			}
		}

		cout << "#" << t << " " << ans << endl;

	}
}

int deepWay(int y, int x) {
	int &ret = dp[y][x];
	
	if (ret != 0) return ret;
	ret = 0;

	// 4방향 검색
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		// error check && less taget
		if (0 <= nx && nx < n && 0 <= ny && ny < n && m[ny][nx] < m[y][x])
			ret = max(ret, deepWay(ny, nx));
	}
	return ret += 1;
}