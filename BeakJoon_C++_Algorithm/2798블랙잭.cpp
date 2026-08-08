/// 2798블랙잭

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 200000000;
	
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;
		while (left < right) {
			if		(i == left) left++;
			else if (i == right) right--;
			else {
				int tmp = a[i] + a[left] + a[right];
				if (tmp <= m) {
					left++;
					if (abs(m - tmp) < abs(m - ans))
						ans = tmp;
				}
				else {
					right--;
				}
			}
		}
	}
	cout << ans << endl;
}

/*

O(n^2 + nlog(n)) 으로 풀이 하는 방법 
1. 소트 한다.
3카드중 1개를 고르고
left + right 하면서 푼다

5 8 9
6 7 9

*/