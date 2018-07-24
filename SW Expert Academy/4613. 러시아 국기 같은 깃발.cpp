/// 4613. 러시아 국기 같은 깃발

#include <iostream>
#include <string>
#include <cstring>

#define endl '\n'

#define min(a, b) a > b ? b : a

using namespace std;

string flag[50];

int counter[50][26];
int w[50], b[50], r[50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, ans;
		memset(counter, 0, sizeof(counter));

		cin >> n >> m;
		ans = n * m;
		for (int i = 0; i < n; i++)
			cin >> flag[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				counter[i][flag[i][j] - 'A']++;
		}
		for (int i = 0; i < n; i++) {
			w[i] = counter[i]['b' - 'a'] + counter[i]['r' - 'a'];
			b[i] = counter[i]['w' - 'a'] + counter[i]['r' - 'a'];
			r[i] = counter[i]['w' - 'a'] + counter[i]['b' - 'a'];
		}
		// 파란색 시작점
		for (int i = 1; i < n - 1; i++) {
			// 빨강색 시작점
			for (int j = i + 1; j < n; j++) {
				int tmp = 0;
				for (int wi = 0; wi < i; wi++)
					tmp += w[wi];
				for (int bi = i; bi < j; bi++)
					tmp += b[bi];
				for (int ri = j; ri < n; ri++)
					tmp += r[ri];
				ans = min(ans, tmp);
			}
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}