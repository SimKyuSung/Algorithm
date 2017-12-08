// 2965Kangaroo

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;	cin >> a >> b >> c;
	printf("%d\n", max(b - a, c - b) - 1);
}
