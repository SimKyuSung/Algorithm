/// 15683.°¨½Ã

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, m;
struct CCTV {
	int x, y, cType, d;
};
vector <vector <int> > deadZone;
vector <CCTV> cctv;
int cctvCount;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int);
void watch(CCTV);
void view(CCTV&);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	deadZone.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int &input = deadZone[i][j];
			cin >> input;
			if (0 < input && input < 6) {
				cctv.push_back({ j, i, input, -1 });
				input = 0;
			}
		}
	}

	cctvCount = cctv.size();
	cout << dfs(0) << endl;
}

int dfs(int x) {
	if (x == cctvCount) {
		for (int i = 0; i < cctvCount; i++)
			watch(cctv[i]);
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret += (deadZone[i][j] == 0);
				deadZone[i][j] &= 6;
			}
		}
		return ret;
	}
	int ret = n * m;
	switch (cctv[x].cType) {
	case 1:
	case 3:
	case 4:
		cctv[x].d = 3;
		ret = min(ret, dfs(x + 1));
		cctv[x].d = 2;
		ret = min(ret, dfs(x + 1));
	case 2:
		cctv[x].d = 1;
		ret = min(ret, dfs(x + 1));
	case 5:
		cctv[x].d = 0;
		ret = min(ret, dfs(x + 1));
	}
	return ret;
}

void watch(CCTV cctv) {
	switch (cctv.cType) {
	case 5:
		view(cctv);
	case 4:
		view(cctv);
	case 3:
		view(cctv);
	case 1:
		view(cctv);
		break;
	case 2:
		view(cctv);
		cctv.d++;
		view(cctv);
	}
}

void view(CCTV &cctv) {
	int x = cctv.x, y = cctv.y;
	while (0 <= x && x < m && 0 <= y && y < n && deadZone[y][x] != 6) {
		deadZone[y][x] = 1;
		x += dx[cctv.d];
		y += dy[cctv.d];
	}
	cctv.d = (cctv.d + 1) % 4;
}