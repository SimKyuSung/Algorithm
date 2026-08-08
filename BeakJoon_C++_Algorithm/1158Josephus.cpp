// 1158Josephus

#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> josephus;
	int n, m, mm = 1, counter = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		josephus.push_back(i);

	int sel = m - 1;
	printf("<%d", josephus[sel]);
	josephus.erase(josephus.begin() + sel);

	while (--n) {
		sel += m - 1;
		if (sel >= n)
			sel = sel % n;
		printf(", %d", josephus[sel]);
		josephus.erase(josephus.begin() + sel);
	}
	printf(">\n");
}

/*
1 2 3 4 5 6 7

  3 1     2 4


*/