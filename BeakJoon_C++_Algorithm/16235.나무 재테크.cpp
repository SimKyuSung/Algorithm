/// 16235.나무 재테크

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int ground[10][10];
int a[10][10];

struct Three {
	int age, cnt;
};
deque <Three> tree[10][10];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			ground[i][j] = 5;
		}
	}
	while (m--) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x - 1][y - 1].push_back({ age, 1 });
	}

	while (k--) {
		// 1. spring && 2. summer
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				int counter, treeSize = tree[i][j].size();
				counter = treeSize;

				for (int t = 0; t < treeSize; t++) {
					if (ground[i][j] - tree[i][j][t].age * tree[i][j][t].cnt >= 0) {
						ground[i][j] -= tree[i][j][t].age * tree[i][j][t].cnt;
						tree[i][j][t].age += 1;
					}
					// 같은 나이의 나무들 중 모두 죽거나 일부가 죽음
					else {
						// 원래 개수
						int all = tree[i][j][t].cnt;

						// 살아 남은 개수
						tree[i][j][t].cnt = ground[i][j] / tree[i][j][t].age;
						
						// 땅 계산
						ground[i][j] %= tree[i][j][t].age;
						ground[i][j] += (all - tree[i][j][t].cnt) * (tree[i][j][t].age >> 1);

						// 나이 계산
						tree[i][j][t].age += 1;

						// 만약 살아 남은 나무 개수가 0이면
						if (tree[i][j][t].cnt == 0)
							t--;
						counter = t;
						
						break;
					}
				}
				for (int t = treeSize - 1; t > counter; t--) {
					ground[i][j] += (tree[i][j][t].age >> 1) * tree[i][j][t].cnt;
					tree[i][j].pop_back();
				}
				//reverse(nextTree[i][j].begin(), nextTree[i][j].end());
			}
		}

		// 3. fall
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (auto x : tree[i][j]) {
					if (x.age % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							int ny = i + dy[d];
							int nx = j + dx[d];
							if (0 <= ny && ny < n && 0 <= nx && nx < n) {
								if (tree[ny][nx].empty() || tree[ny][nx].front().age != 1)
									tree[ny][nx].push_front({ 1, x.cnt });
								else
									tree[ny][nx].front().cnt += x.cnt;
							}
						}
					}
				}
			}
		}


		// 4. winter
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ground[i][j] += a[i][j];
			}
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++)
		//		cout << tree[i][j].size() << ' ';
		//	cout << endl;
		//}

	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			for (auto x : tree[i][j])
				ans += x.cnt;
	}
	cout << ans << endl;


}