/// 14888연산자 끼워넣기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
#define fi first
#define se second

typedef pair<int, int> pp;

const int lim = 1000000000;

vector <int> num;
vector <int> op(4);		// + - * /

pp dfs(int);
inline int oper(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	pp ans = dfs(n - 1);
	cout << ans.fi << endl;
	cout << ans.se << endl;
}

pp dfs(int n) {
	if (n == 0)
		return { num[0], num[0] };
	
	int a1 = -lim;
	int b1 = lim;

	for (int i = 0; i < 4; i++) {
		op[i]--;
		// 계산
		if (op[i] > -1) {
			pp tmp = dfs(n - 1);
			int a2 = oper(tmp.fi, num[n], i);
			int b2 = oper(tmp.se, num[n], i);

			a1 = max(a1, max(a2, b2));
			b1 = min(b1, min(a2, b2));
		}
		op[i]++;
	}
	return { a1, b1 };
}

inline int oper(int a, int b, int i) {
	switch (i) {
	case 0: return a + b;
	case 1: return a - b;
	case 2: return a * b;
	case 3: return a / b;
	default:return 0;
	}
}