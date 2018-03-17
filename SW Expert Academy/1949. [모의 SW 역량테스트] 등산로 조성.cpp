/// 1949. [모의 SW 역량테스트] 등산로 조성

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int m[8][8];
int dp[8][8];

int low[8][8];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 , 0 };

vector < pair <int, int> > top;

int deepWay(int, int);

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(m, 0, sizeof(m));
		memset(dp, 0, sizeof(dp));
		memset(low, 0, sizeof(low));

		int k, maxi = 0;
		cin >> n >> k;

		// 봉우리를 깍아 낼수 있어서 (봉우리를 깍은 후엔)봉우리를 재탐색 해야한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				if (m[i][j] > maxi) {
					maxi = m[i][j];
					top.clear();
					top.push_back({ i , j });
				}
				else if (m[i][j] == maxi) {
					top.push_back({ i, j });
				}
			}
		}

		// 0. 안깎았을때
		int ans = 0;
		for (int i = 0; i < top.size(); i++)
			ans = max(ans, deepWay(top[i].first, top[i].second));

		// 1. 경사로 카운트(주변에 나보다 작은 높이의 개수)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int &lower = low[i][j];
				for (int d = 0; d < 4; d++) {
					int nx = j + dx[d];
					int ny = i + dy[d];
					// error check
					if (0 <= nx && nx < n && 0 <= ny && ny < n && m[ny][nx] < m[i][j])
						lower++;
				}
			}
		}

		// 경사로 카운트 변화가 생기면 함수 실행
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// #원래 경사로 카운트를 기록해 두었다가, 복구한다.
				int orgin = low[i][j];
				//  1 ~ k 깊이로 깍는다.
				for (int k2 = 1; k2 <= k; k2++) {

				}
				low[i][j] = orgin;
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
	return ret + 1;
}