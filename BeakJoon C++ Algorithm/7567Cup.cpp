// 7567Cup
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int ans = 10;
	string cup;
	cin >> cup;
	for (int i = 1; i < cup.length(); i++) {
		if (cup[i] == cup[i - 1])
			ans += 5;
		else
			ans += 10;
	}
	printf("%d\n", ans);
}
