/// 1717집합의 표현

#include <iostream>
#include <vector>

using namespace std;

vector <int> root;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int n, m;
	cin >> n >> m;
	root.resize(n + 1);
	for (int i = 0; i <= n; i++)
		root[i] = i;
	while (m--) {
		int p, a, b;
		cin >> p >> a >> b;
		// 같은 집합 인지 확인
		if (p) {
			while (a != root[a]) a = root[a];
			while (b != root[b]) b = root[b];
			if (a == b)	cout << "YES\n";
			else		cout << "NO\n";
		}
		// 집합 추가
		else {
			// 1. 대표원소 불러오기
			while (a != root[a]) a = root[a];
			while (b != root[b]) b = root[b];
			if (a < b)
				root[b] = a;
			else
				root[a] = b;
		}
	}
}

/*

0	0
1	1
2	2
3	3	3 -> 7
4	4
5	5	5 -> 6
6	6	
7	7

0 2 3
0 5 7
0 3 7


*/