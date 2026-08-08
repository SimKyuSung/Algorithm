/// 1188.음식 평론가

#include <iostream>

#define endl '\n'

using namespace std;

int counter(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cout << counter(n, m) << endl;
}

int counter(int n, int m) {
	if (n % m == 0)
		return 0;
	else if (n == 1)
		return m - 1;
	if (n > m) {
		n %= m;
		return counter(n, m);
	}
	else {
		return n + counter(n, m - n);
	}
}
/*

2 6
받아야 하는양 1 / 3
2개를 2명에게 주기
2번자름
2개를 2명에게 주기
2번자름
2개를 2명에게 주기
끝

3 4 
받아야 하는 양 3 / 4
3개를 3명에주기
3번 자름
3개를 1명에주기
끝

7 6
받아야 하는양 7 / 6
6개를 6명에게 주기
1개를 6명에게 주기 (5등분!)
끝

#####
5 8
받아야 하는 양 5 / 8
5개를 5명에게 나누어줌

5 3 + 5
3명에게 1개씩 주기
2 3
2개를 2명에게 주기
2 1 + 2
2개를 1명에게 주기
=> 7


2 7
2개를 2명에게 주기
2 5 + 2
2 3 + 2
2 1 + 2
끝

*/