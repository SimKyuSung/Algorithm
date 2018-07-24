/// 15686치킨 배달

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int counter;

struct yx {
	int y, x;
};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector <bool> c;
vector <yx> hou;
vector <yx> chi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == 2)
				chi.push_back({ i, j });
			else if (input == 1)
				hou.push_back({ i, j });
		}
	}
	counter = chi.size();

	c.resize(counter);
	for (int i = 0; i < m; i++)
		c[counter - i - 1] = 1;

	int ans = 1000000000;
	do {
		// 거리 계산
		int tmp1 = 0;
		for (int i = 0; i < hou.size(); i++) {
			int tmp2 = 100;
			for (int j = 0; j < counter; j++) {
				// 치킨집 c를 골랐을때
				if (c[j])
					tmp2 = min(tmp2, abs(hou[i].x - chi[j].x) + abs(hou[i].y - chi[j].y));
			}
			tmp1 += tmp2;
		}
		ans = min(ans, tmp1);
	} while (next_permutation(c.begin(), c.end()));

	cout << ans << '\n';
}



/*
드래곤 커브
01:38:00
*/

/*
13 C m
*/