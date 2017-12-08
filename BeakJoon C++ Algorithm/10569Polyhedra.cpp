// 10569Polyhedra

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		// v - e + ans = 2
		// ans = 2 - v + e
		printf("%d\n", 2 - v + e);
	}
}