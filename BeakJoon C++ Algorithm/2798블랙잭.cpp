/// 2798����

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

O(n^2 + nlog(n)) ���� Ǯ�� �ϴ� ��� 
1. ��Ʈ �Ѵ�.
3ī���� 1���� ����
left + right �ϸ鼭 Ǭ��

5 8 9
6 7 9

*/