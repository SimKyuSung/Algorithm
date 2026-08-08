/// 1377.버블 소트

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Pair {
	int x, y;
};
vector <Pair> a;

// 같은 값인 경우 교환 하지 않음
bool cmp(Pair &a, Pair &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x;
		a[i].y = i;
	}

	sort(a.begin(), a.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// 가장 뒤에서 온친구 찾기!
		ans = max(ans, a[i].y - i);
	}
	cout << ans + 1 << endl;
}

/*
5
10	1	5	2	3
1
1	5	2	3	10
2
1	2	3	5	10
3


5
10	5	3	2	1
5

5
10	2	5	3	1
5

5
2	3	5	10	1
5

5
1	2	3	5	10
1

5
1	1	1	1	1
1


5
1	2	1	2	1	문1
1	1	2	1	2	문2
1	1	1	2	2	문3


*/