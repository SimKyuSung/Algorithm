/// 9657돌 게임3

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n;
	cin >> n;
	cout << ((n % 7 && (n + 5) % 7) ? "SK\n" : "CY\n");
}

/*

1, 3, 4
1 개를 못먹는 경우의수

sk	cy	sk	sk	sk	sk	cy	sk	cy	sk	sk	sk	sk	cy	sk	cy	sk
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17

2
7

9
14

16
21

*/