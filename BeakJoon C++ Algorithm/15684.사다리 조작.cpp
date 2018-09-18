/// 15684.��ٸ� ����

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

	// ��ġ x, y �� � ��ȣ�� �������� üũ
	for (int j = 0; j < n; j++) {
		int now = j;
		line[0][j] = j;
		for (int i = 0; i < h; i++) {
			now += ladder[i][now];
			line[i + 1][now] = j;
		}
		lastNum[j] = now;
	}

	// �ؿ��� ���� ��ȯ
	dp[h][0].insert(lastNum);
	for (int i = h - 1; i >= 0; i--) {
		v.clear();
		dfs(i, 0);

		// tmpAns ��ȯ Ƚ��
		for (int tmpAns = 0; tmpAns < ans; tmpAns++) {
			// ������ ��ȯ�ߴ� ����
			for (auto x : dp[i + 1][tmpAns]) {
				int pass1 = 0, pass2 = 0;
				for (int j = 0; j < n; j++)
					pass1 += (x[j] == j);

				// �̹� �࿡�� ��ȯ ������ ����� ���� ����
				for (auto k : v) {
					if (tmpAns + k.size() >= ans)
						continue;
					vector <int> tmp = x;

					// ��ȯ
					for (auto c : k)
						swap(tmp[line[i][c]], tmp[line[i][c + 1]]);
					
					// ���� ������ dp�� ȥ�⵵ ���
					pass2 = 0;
					for (int j = 0; j < n; j++)
						pass2 += (tmp[j] == j);
					
					// ���� �Ȱ��
					if (pass2 == n)
						ans = min(ans, int(tmpAns + k.size()));
					
					// ȥ�⵵�� �þ�� ��� ��ȯ���� ���� -> 12ms ����
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
	// ���� ��ġ���� ��ȯ���� ���� ���
	dfs(a, b + 1);
	// ���� ��ġ���� ��ȯ�ϴ� ���
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