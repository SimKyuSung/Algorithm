/// 15717.떡파이어

#include <iostream>

#define endl '\n'

using namespace std;

const size_t MOD = 1000000007;
size_t powermod(size_t);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	size_t n;
	cin >> n;

	if (n)	cout << powermod(n - 1) << endl;
	else	cout << 1 << endl;
}

size_t powermod(size_t exp) {
	size_t ans = 1, x = 2;
	while (exp) {
		// 1승수 있으면 곱해서 제거
		if (exp % 2)
			ans = (ans * x) % MOD;
		// 2	4	16	256
		x = (x * x) % MOD;
		exp >>= 1;
	}
	return ans;
}
/*
1 : 1
2 : 11
3 : 121
4 : 1331
5 : 14641

1

2
11

3
21
12
111

4
31
22
13
211
121
112
1111

5
41
14
32
23
311
131
113
221
212
122
2111
1211
1121
1112
11111



*/