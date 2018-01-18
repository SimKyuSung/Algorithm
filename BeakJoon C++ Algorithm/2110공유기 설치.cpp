/// 2110공유기 설치

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	h.resize(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	
	sort(h.begin(), h.end());

	int left = 1, right = h[n - 1] - h[0];
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		//cout << left << " " << right << endl;
		int cnt = 1, j = 0;
		for (int i = 1; i < n; i++) {
			// 최소 거리보다 같거나 크면 공유기 설치
			if (h[i] - h[j] >= mid) {
				cnt++;
				j = i;
			}
		}
		// 설치한 공유기가 더 적으면 간격이 너무 간격을 넓게 설치함 -> 더 좁게 만들어 준다.
		if (cnt < c)	right = mid - 1;
		else			left = mid + 1;
	}
	cout << right;
}