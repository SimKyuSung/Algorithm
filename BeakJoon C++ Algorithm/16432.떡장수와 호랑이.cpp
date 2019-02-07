/// 16432.¶±Àå¼ö¿Í È£¶ûÀÌ

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

bool tteok[1004][10];
int counter[1004];

struct T {
	int index, tt;
};
queue <T> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tt;
		cin >> m;
		counter[i] = m;
		for (int j = 0; j < m; j++) {
			cin >> tt;
			tteok[i][tt] = 1;
		}
		if (m == 1)
			q.push({ i, tt });
	}

	while (!q.empty()) {
		int index = q.front().index;
		int tt = q.front().tt;
		q.pop();

		// ¾Õ ³¯ 
		if (index > 0) {
			if (tteok[index - 1][tt]) {
				tteok[index - 1][tt] = 0;
				counter[index - 1]--;
				if (counter[index - 1] <= 0) {
					cout << -1 << endl;
					return 0;
				}
				else if (counter[index - 1] == 1) {
					for (int j = 1; j < 10; j++) {
						if (tteok[index - 1][j])
							q.push({ index - 1, j });
					}
				}
			}
		}

		// µŞ ³¯
		if (index < 1000) {
			if (tteok[index + 1][tt]) {
				tteok[index + 1][tt] = 0;
				counter[index + 1]--;
				if (counter[index + 1] <= 0) {
					cout << -1 << endl;
					return 0;
				}
				else if (counter[index + 1] == 1) {
					for (int j = 1; j < 10; j++) {
						if (tteok[index + 1][j])
							q.push({ index + 1, j });
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			if (tteok[i][j]) {
				cout << j << endl;
				tteok[i + 1][j] = 0;
				break;
			}
		}
	}
}