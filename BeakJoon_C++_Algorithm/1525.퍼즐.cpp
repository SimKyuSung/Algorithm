/// 1525.∆€¡Ò

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

set <int> check;

char table[3][3];
int target = 0;
queue <int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int input, tableToInt = 0, ans = 0;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		tableToInt *= 9;
		tableToInt += input;
		target *= 9;
		target += (i + 1);
	}
	target -= 9;
	if (target == tableToInt) {
		cout << 0 << endl;
		return 0;
	}

	check.insert(tableToInt);
	q.push(tableToInt);

	int qSize = 1, nextQsize;
	while (!q.empty()) {
		nextQsize = 0;

		while (qSize--) {
			tableToInt = q.front();
			q.pop();

			int x, y, nx, ny;
			for (int i = 8; i >= 0; i--) {
				table[i / 3][i % 3] = tableToInt % 9;
				tableToInt /= 9;
			}
			for (int i = 0; i < 9; i++) {
				if (table[i / 3][i % 3] == 0) {
					y = i / 3;
					x = i % 3;
				}
			}

			for (int d = 0; d < 4; d++) {
				nx = x + dx[d];
				ny = y + dy[d];
				if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
					swap(table[y][x], table[ny][nx]);

					int nextTableToInt = 0;
					for (int i = 0; i < 9; i++) {
						nextTableToInt *= 9;
						nextTableToInt += table[i / 3][i % 3];
					}
					if (nextTableToInt == target) {
						cout << ans + 1 << endl;
						return 0;
					}
					if (check.find(nextTableToInt) == check.end()) {
						check.insert(nextTableToInt);
						q.push(nextTableToInt);
						nextQsize++;
					}
					swap(table[y][x], table[ny][nx]);
				}
			}
		}
		qSize = nextQsize;
		ans++;
	}
	cout << -1 << endl;
}