// 1100 chess

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string line;
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		cin >> line;
		for (int j = 0; j < 8; j++)
			if (((j + i) % 2 == 0) && (line[j] == 'F'))
				ans++;
	}
	printf("%d\n", ans);
}