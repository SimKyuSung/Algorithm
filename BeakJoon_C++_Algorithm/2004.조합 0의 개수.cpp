/// 2004조합 0의 개수

#include <iostream>

#define endl '\n'
#define MIN(a, b) ((a)<(b)?(a):(b))
using namespace std;

int counter(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	int five, two;
	cin >> n >> m;

	k = n - m;
	five = counter(n, 5);
	five -= counter(m, 5);
	five -= counter(k, 5);
	two = counter(n, 2);
	two -= counter(m, 2);
	two -= counter(k, 2);

	cout << MIN(five, two) << endl;
}

int counter(int x, int a) {
	int ret = 0;
	while (x)
		ret += x /= a;
	return ret;
}

/*

nCm
k = n - m
n! / (k! * m!)

1
1     1
1     2     1
1     3     3     1          .
1     4     6     4     1       .
1     5     10    10    5     1    .
1     6     15    20    15    6     1
1     7     21    35    35    21    7     1
1    8     28    56    70    56    28    8     1
1    9     36    84   126   126   84    36    9     1
1	10    45   120   210   252    210   120    45    10    1
1	11    55   165   330   462    462   330    165   55    11    1
1	12    66   220   495   792    924   792    495   220    66    12    1
1	13    78    286  715   1287  1716   1716  1287   715    286   78    13    1


5 4 3 2 1 / 4 3 2 1


n		m		k
x00		
x10
x20
x30
x40
x50
x60
x70
x80
x90
n: 0 의 개수
- m

*/