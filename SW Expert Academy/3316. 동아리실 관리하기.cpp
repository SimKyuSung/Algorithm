/// 3316. 동아리실 관리하기

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

size_t p[16];
size_t np[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string x;
		int n;
		memset(np, 0, sizeof(np));
		np[1] = 1;

		cin >> x;
		n = x.size();

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < 16; j++)
				p[j] = np[j];
			memset(np, 0, sizeof(np));
			
			// 다음날 가능성 계산
			for (int j = 1; j < 16; j++) {
				for (int k = 1; k < 16; k++) {
					// 1. 관리자기 있어야 하고, 전날 나온 사람과 1명이라도 중복이 있어야 한다. 
					if (k & (1 << (x[i] - 'A')) && (j & k)) {
						np[k] += p[j];
						np[k] %= 1000000007;
					}
				}
			}

		}

		size_t ans = 0;
		for (int j = 1; j < 16; j++) {
			ans += np[j];
			ans %= 1000000007;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*

BC의 경우 경우의수

1일차		2일차
B + ACD		C + ABD
불가능한 경우의 수
B + AD	2 * 2
C + AD	2 * 2

가능한 모든 경우의수
2 ^ 5 = 32

불가능한 경우의수
AB		CD C
ABC		-
ABD		C
ABCD	-

32 - 3 = 29

가능한 경우의 수만 계산 해보자

C = 2
AC = 4
BC = 4
CD = 3
ABC = 4
ACD = 4
BCD = 4
ABCD = 4

1일차	2일차
AB		AC
		BC
		ABC
		ACD
		BCD
		ABCD

ABC		C
		AC
		BC
		CD
		ABC
		ACD
		BCD
		ABCD

ABD		AC
		BC
		CD
		ABC
		ACD
		BCD
		ABCD

ABCD	C
		AC
		BC
		CD
		ABC
		ACD
		BCD
		ABCD

*/