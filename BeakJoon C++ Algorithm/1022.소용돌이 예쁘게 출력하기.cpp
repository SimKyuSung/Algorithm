/// 1022.소용돌이 예쁘게 출력하기

#include <iostream>
#include <iomanip>

#define max(a, b) a > b ? a : b
#define endl '\n'
#define square(x) ((x)*(x))
// https://stackoverflow.com/questions/14662815/define-squarex-xx

using namespace std;

int sequence(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int maxNum = 0, cipher = 1;
	maxNum = max(maxNum, sequence(r1, c1));
	maxNum = max(maxNum, sequence(r1, c2));
	maxNum = max(maxNum, sequence(r2, c1));
	maxNum = max(maxNum, sequence(r2, c2));
	while (maxNum) {
		cipher++;
		maxNum /= 10;
	}

	for (int i = r1; i <= r2; i++) {
		cout << setw(cipher - 1) << sequence(i, c1);
		for (int j = c1 + 1; j <= c2; j++)
			cout << setw(cipher) << sequence(i, j);
		cout << endl;
	}
	
}
int sequence(int i, int j) {
	int a = 1;
	if (i >= j && i >= -j) {
		a = square(2 * i + 1);
		a += -i + j;
	}
	else if (i > j && i <= -j) {
		a = square(j * 2, 2) - (j * 2) + 1;
		a += i + j;
	}
	else if (i <= j && i < -j) {
		a = square(i * 2) + 1;
		a += + i - j;
	}
	else if (i < j && i >= -j) {
		a = square(j * 2, 2) - (j * 2) + 1;
		a += -i - j;
	}
	return a;
}
/*
[0. 0] = 1
반 시계 방향

[-2,-2]	[-2,-1]	[-2, 0]	[-2, 1]	[-2, 2]
[-1,-2]	[-1,-1]	[-1, 0]	[-1, 1]	[-1, 2]
[ 0,-2]	[ 0,-1]	[ 0, 0]	[ 0, 1]	[ 0, 2]
[ 1,-2]	[ 1,-1]	[ 1, 0]	[ 1, 1]	[ 1, 2]
[ 2,-2]	[ 2,-1]	[ 2, 0]	[ 2, 1]	[ 2, 2]

\ => y = x
/ => y = -x

-3 -3 3 3
3 3 3 3 3 3 4
2 3 3 3 3 4 4
2 2 3 3 4 4 4
2 2 2 1 4 4 4
2 2 1 1 1 4 4
2 1 1 1 1 1 4
1 1 1 1 1 1 1
*/
/*
S = n(2a + (n - 1)d) / 2
 1. 
if (i >= j && i >= -j)
a = pow(2 * i + 1, 2);
1	9	25	49

 2.
if (i > j && i <= -j)

0	-1	-2	-3
1	7	21	43
6	14	22
8	8
a = -j * (12 + (-j - 1) * 8) / 2 + 1
a = -j * (4 - 8 * j) / 2 + 1
a = j * (8 * j - 4) / 2 + 1
a = j * 2 * (2 * j - 1) + 1
A ^ 2 - A + 1

 3. 
if (i <= j && i < -j)

-0	-1	-2	-3	-4
1	5	17	37	65
4	12	20	28
8	8	8	8
a = -i * (8 + (-i - 1) * 8) / 2 + 1
a = i * i * 4 + 1
a = pow(i + 2, 2) + 1

 4. 
if (i < j && i >= -j)
1	3	13	31	
2	10	18
8	8	8  

a = j(4 + (j - 1)8) / 2 + 1
a = j(8j - 4) / 2 + 1
a = j(4j - 2) + 1
a = j * 2 * (2 * j - 1) + 1

*/