// 10821IntCounter

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string line;
	cin >> line;
	int counter = 1;
	for (int i = 0; i < line.length(); i++)
		if (line[i] == ',')
			counter++;
	printf("%d\n", counter);
}