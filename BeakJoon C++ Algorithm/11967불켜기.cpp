/// 11967���ѱ�

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct coordinate {
	int y, x;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector < vector < vector <coordinate> > > edge;
bool room[100][100];
bool ch1[100][100];
bool ch2[100][100];
vector <coordinate> access;

int n, m;
void dfs1(int, int);
void dfs2(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	edge.resize(n, vector < vector <coordinate> >(n));

	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		edge[y - 1][x - 1].push_back({ b - 1, a - 1 });
	}

	room[0][0] = 1;
	ch2[0][0] = 1;
	access.push_back({ 0, 0 });
	dfs1(0, 0);

	int counter = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			counter += room[i][j];
	cout << counter << '\n';
}

void dfs1(int y, int x) {
	// 1. ���ѱ�!
	for (int i = 0; i < edge[y][x].size(); i++) {
		coordinate next = edge[y][x][i];
		room[next.y][next.x] = 1;
	}

	// 2. ���� ����� ���� ã��!
	int start = access.size(), end;
	for (int i = 0; i < access.size(); i++) {
		for (int d = 0; d < 4; d++) {
			int xx = access[i].x + dx[d];
			int yy = access[i].y + dy[d];
			// ���� ���� ����, ���� ���� �ִٸ�, ���� �߰��ϴ� �Լ�
			if (0 <= xx && xx < n && 0 <= yy && yy < n)
				if (!ch1[yy][xx] && room[yy][xx])
					dfs2(yy, xx);
		}
	}

	// 3. ���� ����� ���� ������� dfs1 ����
	end = access.size();
	ch2[y][x] = 1;
	for (int i = start; i < end; i++) {
		if (!ch2[access[i].y][access[i].x])
			dfs1(access[i].y, access[i].x);
	}
}

void dfs2(int y, int x) {
	ch1[y][x] = 1;
	access.push_back({ y, x });
	for (int d = 0; d < 4; d++) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (0 <= xx && xx < n && 0 <= yy && yy < n)
			if (!ch1[yy][xx] && room[yy][xx])
				dfs2(yy, xx);
	}
}

