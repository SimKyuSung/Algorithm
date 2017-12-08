// 1074Z

#include <cstdio>
#include <iostream>

using namespace std;

int solve(int, int);

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << solve(r, c) << endl;
}

int solve(int r, int c) {
	int ret = 0;
	if (r % 2) {
		ret += 2;
		r--;
	}
	if (c % 2) {
		ret += 1;
		c--;
	}
	cout << r << " " << c << endl;
	if (r != 0 || c != 0)
		ret += 4 * solve(r / 2, c / 2);
	return ret;
}

/*

0	1	4	5	16	17	20	21
2	3	6	7	18	19	22	23
8	9	12	13	24	25	28	29
10	11	14	15	26	27	30	31
32	33	36	37	48	49_	52	53
34	35	38	39	50	51	54	55
40	41	44	45	56	57	60	61
42	43	46	47	58_	59	62	63

0 0		0
0 1		1
1 0		2
1 1		3

0 2		4
0 3		5
1 2		6
1 3		7

2 0		8
2 1		9
3 0		10
3 1		11

2 2		12
2 3		13
3 2		14
3 3		15

0
1
3
7
15
31
63

// È¦¼ö -> Â¦¼ö

(0, 2) -> 
(4, 5) -> (4, 4)
(7, 4) -> (6, 4) -> (3, 2)


*/