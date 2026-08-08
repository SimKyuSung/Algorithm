// 2493Tower

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

stack <pair <int, int> > tower;
vector <int> ans;

int main()
{
	int n, input;
	cin >> n;
	tower.push({ 1000000000, 0 });
	for (int i = 1; i <= n; i++) {
		cin >> input;
		while (tower.top().first <= input)
			tower.pop();
		ans.push_back(tower.top().second);
		tower.push({ input, i });
	}
	for (int i = 0; i < n - 1; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n - 1]);
}

/*
5
6 9 5 7 4
0 0 2 2 4
*/