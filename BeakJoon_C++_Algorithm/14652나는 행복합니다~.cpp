/// 14652나는 행복합니다~

#include <iostream>

using namespace std;

int main()
{
	int n, m, k;	cin >> n >> m >> k;
	int y = k / m, x = k % m;
	cout << y << " " << x;
}

/*
0  1  2  3
7  6  5  4
8  9  10 11
15 14 13 12
16 17 18 19
23 22 21 20
*/