/// 2382. [모의 SW 역량테스트] 미생물 격리

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

//#include <list>

#define endl '\n'

using namespace std;

struct Microbe {
	int y, x, mSize, d;
};

bool cmp(Microbe u, Microbe v) {
	return u.mSize < v.mSize;
}
vector <Microbe> microbe;
int cellM[100][100];
int cellD[100][100];

// 상 좌 하 우
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, k;
		int y, x, mSize = 0, d;
		memset(cellM, -1, sizeof(cellM));
		memset(cellD, -1, sizeof(cellD));

		cin >> n >> m >> k;
		microbe.resize(k);
		for (int i = 0; i < k; i++) {

			cin >> y >> x >> mSize >> d;
			if (d == 2)
				d = 3;
			else if (d == 3)
				d = 2;
			d--;
			microbe[i] = { y, x, mSize, d };
		}
		sort(microbe.begin(), microbe.end(), cmp);

		while (m--) {
			while (!microbe.empty()) {
				Microbe now = microbe.back();
				microbe.pop_back();
				y = now.y;
				x = now.x;
				d = now.d;
				mSize = now.mSize;

				y += dy[d];
				x += dx[d];
				if (y == 0 || y == n - 1 || x == 0 || x == n - 1) {
					mSize >>= 1;
					d = (d + 2) % 4;
					cellM[y][x] = mSize;
					cellD[y][x] = d;
				}
				else if (cellD[y][x] != -1)
					cellM[y][x] += mSize;
				else {
					cellM[y][x] = mSize;
					cellD[y][x] = d;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (cellM[i][j] != -1) {
						microbe.push_back({ i, j, cellM[i][j], cellD[i][j] });
						cellM[i][j] = -1;
						cellD[i][j] = -1;
					}
				}
			}
			sort(microbe.begin(), microbe.end(), cmp);
		}
		int ans = 0;
		while (!microbe.empty()) {
			ans += microbe.back().mSize;
			microbe.pop_back();
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}