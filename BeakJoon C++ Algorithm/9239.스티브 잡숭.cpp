/// 9239.스티브 잡숭

#include <iostream>
#include <string>
#include <cmath>

#define endl '\n'

using namespace std;

struct Fraction {
	int a, b;
};
inline int getGcd(int, int);
inline int cypherCount(int);
inline Fraction getX(int);
inline void testCasePrint();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	int a = 0, b = 0, ten = 1, gcd, i, cypher = 0;
	for (i = 0; i < input.size(); i++) {
		if (input[i] == '.')
			break;
		a *= 10;
		a += input[i] - '0';
	}
	i++;
	for (; i < input.size(); i++, cypher++) {
		b *= 10;
		b += input[i] - '0';
	}
	ten = pow(10, cypher);
	a *= ten;
	a += b;

	gcd = getGcd(a, ten);
	b = a / gcd;
	a = ten / gcd;
	Fraction x = { a, b };

	//cout << b << ' ' << a << endl;
	//testCasePrint();

	if (a == b) {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 0; k < i; k++)
					cout << j;
				cout << endl;
			}
		}
		return 0;
	}


	bool ac = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 10; j++) {
			double left = j, right = j, dx = x.b / (double)x.a;
			for (int k = 0; k < i; k++) {
				left *= 10;
				right *= 10;
				right += 9;
			}
			//cout << left << ' ' << right << endl;
			Fraction leftX = getX(left);
			Fraction rightX = getX(right);
			if (leftX.b / left <= dx && dx <= rightX.b / right) {
				while (leftX.b / left <= rightX.b / right) {
					int mid = (left + right) / 2;
					double midD = getX(mid).b / (double)mid;
					//cout << midD << endl;
					if (dx < midD) {
						right = mid - 1;
						rightX = getX(mid - 1);
					}
					else {
						left = mid + 1;
						leftX = getX(mid + 1);
					}
				}

				if (rightX.a / (double)x.a == rightX.b / (double)x.b) {
					ac = 1;
					cout << (int)right << endl;
				}
			}
		}
	}

	if (!ac)
		cout << "No solution" << endl;
}

inline int getGcd(int a, int b) {
	while (b) {
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}
inline int cypherCount(int a) {
	int ret = 0;
	while (a) {
		a /= 10;
		ret++;
	}
	return ret;
}

inline void testCasePrint() {
	for (int i = 1; i <= 2000; i++)
		cout << getX(i).b << ' ' << i << endl;
}

inline Fraction getX(int i) {
	int ten = pow(10, cypherCount(i) - 1);
	int b = (i % ten) * 10 + i / ten;
	return { i, b };
}
/*

1 <= x < 1000
1 <= ans < 100000000

// 첫 자리를 맨뒤로 보낸 수
function(a)

1
2
3
4
5
6
7
8
9
10 = 1
11 = 11
12 = 21
13 = 31
14 = 41				14 * (41/14)

1. x 를 기약 분수 형태
b / a

2. b / a 의 배수중에 function(a) = b
a를 출력

3. a * x 가 1억을 넘어가면 중지

*/

/*
13/5
13 * 27 / 5 * 27
13 * 54 / 5 * 54
13 * 27027 / 5 * 27027
13 * 54054 / 5 * 54054

*/

/*

1
1-9

0.1	1	1.75	2.3846153...	2.92857142	3.4
10	11	12		13				14			15

16	3.8125
17	4.1764705882352941176470588235294
18	4.5


i: 1~8
j:	1~9

9 * 1 / (10 - x) + 0.5


*/