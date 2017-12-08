/// 1704붕어빵타이쿤

#include <iostream>
#include <vector>

using namespace std;

vector <vector <bool> > a;
vector <vector <bool> > b;
vector <vector <bool> > tmp;
vector <vector <bool> > ans;

int ansCounter = 100000;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { -1, 1, 0, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	a.resize(n + 2, vector<bool>(m + 2, false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			cin >> tmp;
			a[i][j] = tmp;
		}
	}

	for (int t = 0; t < 1 << m; t++) {
		// 맨 윗줄의 모든 경우의 수
		int counter = 0;
		b = a;
		tmp = vector <vector <bool> >(n + 2, vector <bool>(m + 2, false));
		for (int j = 1; j <= m; j++) {
			if ((t >> (m - j)) % 2) {
				tmp[1][j] = true;
				counter++;
				for (int d = 0; d < 5; d++) {
					int xx = dx[d] + j;
					int yy = dy[d] + 1;
					b[yy][xx] = !b[yy][xx];
				}
			}
		}

		// 밑에 조정
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (b[i - 1][j]) {
					tmp[i][j] = true;
					counter++;
					for (int d = 0; d < 5; d++) {
						int xx = dx[d] + j;
						int yy = dy[d] + i;
						b[yy][xx] = !b[yy][xx];
					}
				}
			}
		}

		bool flag = true;
		for (int j = 1; j <= m; j++)
			if (b[n][j]) flag = false;

		if (flag) {
			if (counter < ansCounter) {
				ansCounter = counter;
				ans = tmp;
			}
		}
	}
	if (ansCounter == 100000)  cout << "IMPOSSIBLE\n";
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
}

/*

4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1

0 0 0 0
1 0 0 1
1 0 0 1
0 0 0 0

-> 같은 곳을 2번 이상 뒤집지 않는다.
-> 맨윗줄의 상태가 정의 되면
-> 그다음 줄은 상태가 종속된다.
-> 해답을 찾았다고 해서 항상 그답이 최솟값이라는 보장이 없다.


*/