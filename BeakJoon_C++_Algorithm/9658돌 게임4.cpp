/// 9658돌 게임4

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n;
	cin >> n;
	cout << (((n + 4) % 7 && (n + 6) % 7) ? "SK\n" : "CY\n");
}

/*

1, 3, 4
마지막 1 개를 먹으면 망함 


cy	sk	cy	sk	sk	sk	sk	cy	sk	cy	sk	sk	sk	sk	cy	sk	cy
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17

1
3

8
10

15
17

*/