/// 4699. 콩순이의 가장 싼 팰린드롬

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, k, w[26], ans = 0;
		string p;
		memset(w, 0, sizeof(w));

		cin >> n >> k >> p;
		for (int i = 0; i < k; i++) {
			int ins, del;
			cin >> ins >> del;
			w[i] = min(ins, del);
		}

		// 비용, 문자열
		for (int i = 0; i < n; i++) {
			// 1. 중앙일때
			int sum = 0;
			int left = i - 1, right = i + 1;
			while (0 <= left && right < n) {
				// 1-1. 같은 경우 pop
				if (p[left] == p[right]) {
					left--;
					right++;
				}
				// 1-2. 다른 경우 반대쪽을 살린다고 가정하고 드는 비용을 계산
				else {  
					int lv = 0, rv = 0;
					int l = left - 1;
					// 왼쪽을 모두 삭제
					while (0 <= l && p[l] != p[right])
						lv += w[l];
					// 끝까지 가도 없으면, 본인도 삭제 대상
					if (l == -1)
						lv += w[right];

					int r = right + 1;
					while (r < n && p[r] != p[left])
						rv += w[r];
					if (r == n)
						lv += w[left];
				}
			}
			while (0 <= left) {

			}
			while (right < l) {

			}
			ans = min(ans, sum);
			// 2. 왼쪽일때
			sum = 0;


			ans = min(ans, sum);
		}

		cout << '#' << t << ' ' << ans << endl;
	}

}

/*

1
4 3
abcb
40
35
20

abcb	a(40)	bcb		40
					
		b(35)	abc		a(40)	bc		b(35)	c	110
										c(20)	b	95
						c(20)	ab		a(40)	b	95
										b(35)	a	90


	cacbacba
1. a를 삭제하거나, 삽입(40)
	cacbacb			-> 1-1 c를 삭제 또는 삽입(20)
					-> acbacb
									-> 1-1-1 a를 삭제 (40)
									-> cbacb(100) 생략
									-> 1-1-2 b를 삭제 (35)
									-> acbac(95) 생략

					-> 1-2 b를 삭제 또는 삽입(35)
					-> cacbac		-> acbac(75)	->	1-2-1 a 삭제(40)
													->	cbac(115)		->	ba(115)	-> b 삭제하면 115 + 35 = 150

													->	1-2-2 c 삭제(20)
													->	acba(95)		->	cb(95)	-> c 삭제하면 95 + 20 = 115
						
2. c를 삭제하거나, 삽입(20) ve4evbjn
	acbacba			->              -> cbacb(20)	->	2-1 c 삭제(20)
													->	bacb(40)		->	ac(40)	-> c 삭제하면 40 + 20 = 60
													->	2-2 b 삭제(35)
													->	abac(55)		->	2-2-1 a 삭제(40)
																		->	bac(95) -> bc 삭제하면 95 + 55 = 150
																		->	2-2-2 c 삭제(20)
																		->	aba = 75

cacbacba

ababa c만 삭제 해서 60

abcdefg
1. a	bcdefg


2. g	abcdef		


left, right

26
26 * 26
26 * 26 * 26

abca
10
50
100
 c 가 중심 일때
a를 삭제 할까, b를 삭제 할까?
b 삭제 하면 비용 50
a 삭제 하면 비용 10 + 50 + 10
둘다 삭제 하면 비용 10 * 50 + 10
abca
aca 50
aba 100
b	120
c	70

123456
111111



b def a   c   b def a
      a   c         a(bdef)
b	      c   b(defa)
      f   c       f(bde)   
b	      c   b(def)
*/