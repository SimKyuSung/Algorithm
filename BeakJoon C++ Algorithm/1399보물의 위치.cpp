/// 1399보물의 위치

#include <iostream>
#include <vector>

using namespace std;

// 북, 서, 남, 동
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k, m, gold = 1;
		long long x = 0, y = 0;
		cin >> k >> m;

		// cycle 찾기
		vector < pair<int, int> > cycle;
		bool f = false;
		int s;
		for (int c = 0; c < k; c++) {
			x += dx[c % 4] * gold;
			y += dy[c % 4] * gold;
			for (int i = 0; i < cycle.size(); i++) {
				if (cycle[i] == pair <int, int> {x, y}) {
					s = i;
					f = true;
					break;
				}
			}
			if (f) break;
			//cout << x << " " << y << "\n";
			cycle.push_back({ x, y });
			gold *= m;
			while (gold > 9) {
				int tmp = gold;
				gold = 0;
				while (tmp) {
					gold += tmp % 10;
					tmp /= 10;
				}
			}
		}
		if (f) {
			k -= s + 1;
			int index = k % (cycle.size() - s);
			x = cycle[s + index].first;
			y = cycle[s + index].second;
		}
		cout << x << " " << y << "\n";
	}
}

/*
input
k <= 1000000000
m <= 1000

k 가 10^9 임으로 싸이클을 찾아야 한다.
m = 1	1 1 1 1  1  1  1  1

m = 2	1 2 4 8  16 14 10 
				 7	5	1
		1 2 4 8  7  5

m = 3	1 3 9 27 27
			  9  9

m = 4	1 4 16 28	 
			 7  1
		1 4 7

m = 5	1 5 25 35 40 20 10
			7	8  4  2

ex)
		 -	   -      -
1 2 7 (8 3 5 6 9) 8 3 5 6 9)
	  (8 3 5 6 9)

k = 5
y1i = 0

12
1 x x x 7 x x x 4 x x x 1



*/