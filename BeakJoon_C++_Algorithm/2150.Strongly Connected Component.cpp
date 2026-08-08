/// 2150.Strongly Connected Component

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

const int MAX = 10001;

vector <int> edgeA[MAX];
vector <int> edgeB[MAX];

bool check[MAX];

vector <int> counter;

void dfs1(int);
void dfs2(int, vector <int>&);

vector <vector <int> > ans;
bool cmp (vector <int> &a, vector <int> &b) {
	return a[0] < b[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int v, e, a, b;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		a--, b--;
		edgeA[a].push_back(b);
		edgeB[b].push_back(a);
	}

	for (int i = 0; i < v; i++) {
		if (!check[i])
			dfs1(i);
	}

	//for (int i = 0; i < v; i++)
	//	cout << i + 1 << ' ' << counter[i] + 1 << endl;

	memset(check, 0, sizeof(check));
	for (int i = counter.size() - 1; i >= 0; i--) {
		if (!check[counter[i]]) {
			vector <int> tmpAns;
			dfs2(counter[i], tmpAns);
			sort(tmpAns.begin(), tmpAns.end());
			ans.push_back(tmpAns);
		}
	}

	sort(ans.begin(), ans.end(), cmp);

	cout << ans.size() << endl;
	for (auto &i : ans) {
		for (auto &j : i)
			cout << j << ' ';
		cout << "-1\n";
	}
}

void dfs1(int a) {
	check[a] = 1;
	for (auto &x : edgeA[a]) {
		if (!check[x])
			dfs1(x);
	}
	counter.push_back(a);
}
void dfs2(int a, vector <int>& tmpAns) {
	check[a] = 1;
	tmpAns.push_back(a + 1);
	for (auto &x : edgeB[a]) {
		if (!check[x])
			dfs2(x, tmpAns);
	}
}