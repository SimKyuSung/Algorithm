/// 10819차이를 최대로

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector <int> arr;
int ans = 0;

inline void swap(int &, int &);
inline void cal();

void solve(int, int);

int main()
{
	cin >> n;
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(0, n);
	cout << ans << endl;
}

inline void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

inline void cal() {
	int tmp = 0;
	for (int i = 1; i < n; i++)
		tmp += abs(arr[i] - arr[i - 1]);
	ans = max(ans, tmp);

}
// 순열 알고리즘
/*
0. 종료조건
1. 스왑 안하고 그냥 출력
2. 스왑하고 재귀
*/
void solve(int x, int depth) {
	if (x == depth) {
		cal();
		return;
	}
	solve(x + 1, depth);
	for (int i = x + 1; i < n; i++) {
		swap(arr[i], arr[x]);
		solve(x + 1, depth);
		swap(arr[i], arr[x]);
	}
	return;
}
