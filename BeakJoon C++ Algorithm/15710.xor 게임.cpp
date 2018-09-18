/// 15710.xor ����

#include <iostream>

#define endl '\n'

using namespace std;

const int MOD = 1000000007;

size_t powermod(size_t, size_t, size_t);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	size_t a, b, n;
	cin >> a >> b >> n;
	if (n == 0)
		cout << (a == b) << endl;
	else {
		int c = powermod(2, n - 1, MOD);
		cout << powermod(c, 32, MOD) << endl;
	}
}

size_t powermod(size_t base, size_t exp, size_t mod) {
	size_t ans = 1, x = base % mod;
	while (exp) {
		// 1�¼� ������ ���ؼ� ����
		if (exp % 2)
			ans = (ans * x) % mod;
		// 2	4	16	256
		x = (x * x) % mod;
		exp >>= 1;
	}
	return ans;
}

/*

a -> b �� ���µ� n �� ��ȯ�� �Ѵ�.

2 3 0	0
2 3 1	1^32
2 3 2	2^32
2 3 3	4^32
2 3 4	8^32	

������ 00 �Ǵ� 11
�ٸ��� 01 �Ǵ� 10

0000 0010
xxxx xxxx
0000 0011
1111 1111

0000 0010
xxxx xxxx
xxxx xxxx
0000 0011

2222 2222


0000 0010
xxxx xxxx
xxxx xxxx
xxxx xxxx
0000 0011

4444 4444

0000 0010

0000 0011

0
0
0
0

0
0
1
1

0
1
0
1

0
1
1
0

1
0
0
1

1
0
1
0

1
1
0
0

1
1
1
1


*/