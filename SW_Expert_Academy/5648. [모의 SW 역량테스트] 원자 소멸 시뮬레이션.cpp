/// 5648. [모의 SW 역량테스트] 원자 소멸 시뮬레이션

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct Atom {
	short y, x, d, k;
};
struct Impact {
	short id1, id2;
};


Atom a[1000];
queue <Impact> impact[4001];
bool check[1000];
int impactList[2000];

// 상(0), 하(1), 좌(2), 우(3)
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, ans = 0;
		short x, y, d, k;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> d >> k;
			x = x * 2;
			y = y * 2;
			a[i] = { y, x, d, k };
			check[i] = 1;
		}

		for (short i = 0; i < n; i++) {
			for (short j = i + 1; j < n; j++) {
				y = a[i].y - a[j].y;
				x = a[i].x - a[j].x;
				int ddy = dy[a[i].d] - dy[a[j].d];
				int ddx = dx[a[i].d] - dx[a[j].d];
				int dty = 0, dtx = 0;
				
				if (ddy == 0 && ddx == 0)
					continue;
				
				if (ddy != 0) {
					if (y == 0)
						continue;
					dty = y / ddy;
				}
				else if (y)
					continue;

				if (ddx != 0) {
					if (x == 0)
						continue;
					dtx = x / ddx;
				}
				else if (x)
					continue;
				
				if (dty == 0)
					dty = dtx;
				if (dtx == 0)
					dtx = dty;
				
				if (dty == dtx) {
					//cout << i << ' ' << j << ' ' << dty << endl;
					if (dty < 0) {
						dty *= -1;
						impact[dty].push({ i, j });
					}
				}
			}
		}
		for (int i = 1; i <= 4000; i++) {

			int listCounter = 0;
			while(!impact[i].empty()) {
				Impact cruch = impact[i].front();
				impact[i].pop();
				if (check[cruch.id1] && check[cruch.id2]) {
					impactList[listCounter++] = cruch.id1;
					impactList[listCounter++] = cruch.id2;
				}
			}
			while (listCounter--) {
				if (check[impactList[listCounter]])
					ans += a[impactList[listCounter]].k;
				check[impactList[listCounter]] = 0;
			}
		}

		memset(check, 0, sizeof(check));
		cout << '#' << t << ' ' << ans << endl;
	}
}

/*


2
4
-1000 0 3 5				-2000, 0 : 2, 0			-1000, -1000 : 1 : 1			-1000, 1000 : 1, -1
1000 0 2 3
0 1000 1 7
0 -1000 0 9

4
-1 1 3 3
0 1 1 1
0 0 2 2
-1 0 0 9



*/