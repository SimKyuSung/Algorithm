/// 9656�� ����2

#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n;
	cin >> n;
	cout << ((n % 2 == 0) ? "SK" : "CY");
}

/*

cy	sk	cy	sk
1	2	3	4
	4	5	6
		7	8
			10

*/