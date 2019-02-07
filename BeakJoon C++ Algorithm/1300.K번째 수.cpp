/// 1300.K¹øÂ° ¼ö

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	size_t n, k, i, j;
	cin >> n >> k;

	i = (k - 1) / n + 1;
	j = k % n + 1;
	cout << i * j << endl;
}

/*

1 2 3		1	2	3	4	5	6	7	8	9
4 5 6		2	4	6	8	10	12
7 8 9		3	6	9	12	15	18
			4	8	12	16	20
			5	10	15	20	25
			6	12
			7	14
			8	16

1	4	9	16	25
2	4	
2	4
3	5
3	5
	6
	6
	6
	6
	7
	7
	8
	8
	8
	8


*/