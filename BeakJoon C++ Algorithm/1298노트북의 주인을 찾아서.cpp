/// 1298노트북의 주인을 찾아서

/// 11375열혈강호

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector < vector <int> > edge;
vector <int> noteBook;
vector <int> people;
bool visited[1000];

bool dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	int n, m, ans = 0;
	cin >> n >> m;
	edge.resize(n);
	noteBook.resize(m, -1);
	people.resize(n, -1);
	for (int i = 0; i < m; i++) {
		int pNum, nNum;
		cin >> pNum >> nNum;
		edge[pNum - 1].push_back(nNum - 1);
	}
	for (int i = 0; i < n; i++) {
		if (people[i] == -1) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))
				ans++;
		}
	}
	printf("%d", ans);
}

bool dfs(int e) {
	visited[e] = true;
	for (int j : edge[e]) {
		if (noteBook[j] == -1 || (!visited[noteBook[j]] && dfs(noteBook[j]))) {
			noteBook[j] = e;
			people[e] = j;
			return true;
		}
	}
	return false;
}

/*
매칭의 최대 개수 구하기
*/