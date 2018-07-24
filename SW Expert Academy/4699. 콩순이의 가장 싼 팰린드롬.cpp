/// 4699. ������� ���� �� �Ӹ����

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

		// ���, ���ڿ�
		for (int i = 0; i < n; i++) {
			// 1. �߾��϶�
			int sum = 0;
			int left = i - 1, right = i + 1;
			while (0 <= left && right < n) {
				// 1-1. ���� ��� pop
				if (p[left] == p[right]) {
					left--;
					right++;
				}
				// 1-2. �ٸ� ��� �ݴ����� �츰�ٰ� �����ϰ� ��� ����� ���
				else {  
					int lv = 0, rv = 0;
					int l = left - 1;
					// ������ ��� ����
					while (0 <= l && p[l] != p[right])
						lv += w[l];
					// ������ ���� ������, ���ε� ���� ���
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
			// 2. �����϶�
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
1. a�� �����ϰų�, ����(40)
	cacbacb			-> 1-1 c�� ���� �Ǵ� ����(20)
					-> acbacb
									-> 1-1-1 a�� ���� (40)
									-> cbacb(100) ����
									-> 1-1-2 b�� ���� (35)
									-> acbac(95) ����

					-> 1-2 b�� ���� �Ǵ� ����(35)
					-> cacbac		-> acbac(75)	->	1-2-1 a ����(40)
													->	cbac(115)		->	ba(115)	-> b �����ϸ� 115 + 35 = 150

													->	1-2-2 c ����(20)
													->	acba(95)		->	cb(95)	-> c �����ϸ� 95 + 20 = 115
						
2. c�� �����ϰų�, ����(20) ve4evbjn
	acbacba			->              -> cbacb(20)	->	2-1 c ����(20)
													->	bacb(40)		->	ac(40)	-> c �����ϸ� 40 + 20 = 60
													->	2-2 b ����(35)
													->	abac(55)		->	2-2-1 a ����(40)
																		->	bac(95) -> bc �����ϸ� 95 + 55 = 150
																		->	2-2-2 c ����(20)
																		->	aba = 75

cacbacba

ababa c�� ���� �ؼ� 60

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
 c �� �߽� �϶�
a�� ���� �ұ�, b�� ���� �ұ�?
b ���� �ϸ� ��� 50
a ���� �ϸ� ��� 10 + 50 + 10
�Ѵ� ���� �ϸ� ��� 10 * 50 + 10
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