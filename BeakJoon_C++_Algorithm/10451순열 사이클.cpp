/// 10451순열 사이클

#include <iostream>
#include <vector>

using namespace std;

vector <int> p(1001);
vector <bool> c;

void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;		cin >> t;
	while (t--) {
		int n, size = 0;				cin >> n;
		for (int i = 1; i <= n; i++)	cin >> p[i];
		c = vector<bool>(1001, false);
		for (int i = 1; i <= n; i++) {
			if (!c[i]) {
				size++;
				dfs(i);
			}
		}
		cout << size << "\n";
	}
}

void dfs(int x) {
	c[x] = true;
	if (!c[p[x]]) dfs(p[x]);
}