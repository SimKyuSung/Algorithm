/// 15684.사다리 조작

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;

int n, m, h;

vector <vector <int> > ladder;
vector <vector <int> > line;
vector <int> lastNum;
set <vector <int> > dp[31][4];

int ans = 4;
vector <vector <int> > v;
vector <int> counter;
void dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> h;
	ladder.resize(h, vector<int>(n));
	line.resize(h + 1, vector <int>(n));
	lastNum.resize(n);

	while (m--) {
		int a, b;
		cin >> a >> b;
		ladder[a - 1][b - 1] = 1;
		ladder[a - 1][b] = -1;
	}

	// 위치 x, y 에 어떤 번호가 지나가는 체크
	for (int j = 0; j < n; j++) {
		int now = j;
		line[0][j] = j;
		for (int i = 0; i < h; i++) {
			now += ladder[i][now];
			line[i + 1][now] = j;
		}
		lastNum[j] = now;
	}

	// 밑에서 부터 교환
	dp[h][0].insert(lastNum);
	for (int i = h - 1; i >= 0; i--) {
		v.clear();
		dfs(i, 0);

		// tmpAns 교환 횟수
		for (int tmpAns = 0; tmpAns < ans; tmpAns++) {
			// 이전에 교환했던 흔적
			for (auto x : dp[i + 1][tmpAns]) {
				int pass1 = 0, pass2 = 0;
				for (int j = 0; j < n; j++)
					pass1 += (x[j] == j);

				// 이번 행에서 교환 가능한 경우의 수를 대입
				for (auto k : v) {
					if (tmpAns + k.size() >= ans)
						continue;
					vector <int> tmp = x;

					// 교환
					for (auto c : k)
						swap(tmp[line[i][c]], tmp[line[i][c + 1]]);
					
					// 새로 생성된 dp의 혼잡도 계산
					pass2 = 0;
					for (int j = 0; j < n; j++)
						pass2 += (tmp[j] == j);
					
					// 답이 된경우
					if (pass2 == n)
						ans = min(ans, int(tmpAns + k.size()));
					
					// 혼잡도가 늘어나는 경우 교환하지 않음 -> 12ms 줄임
					if (pass2 >= pass1)
						dp[i][tmpAns + k.size()].insert(tmp);
				}
			}
		}
	}
	if (ans == 4) ans = -1;
	cout << ans << endl;
}

void dfs(int a, int b) {
	if (b == n - 1) {
		v.push_back(counter);
		return;
	}
	// 현재 위치에서 교환하지 않을 경우
	dfs(a, b + 1);
	// 현재 위치에서 교환하는 경우
	if (ladder[a][b] == 0 && ladder[a][b + 1] == 0) {
		ladder[a][b] = 1;
		ladder[a][b + 1] = -1;
		counter.push_back(b);
		dfs(a, b + 1);
		counter.pop_back();
		ladder[a][b] = 0;
		ladder[a][b + 1] = 0;
	}
}