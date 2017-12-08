/// 1002터렛

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x1, y1, r1, x2, y2, r2;
	int xr, yr, r;
	int n;

	cin >> n;

	// 계산 정밀도를 위해서 루트 사용금지
	for (int i = 0; i < n; i++) {
		// 입룍받기!
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		xr = x1 - x2;
		yr = y1 - y2;
		// 또는 math.h 의 pow 함수 사용
		xr = xr * xr;
		yr = yr * yr;

		// 두 원이 외부에 있을 경우, 내부이 있을 경우 나누어짐
		if (((xr + yr) > (r1 * r1)) && ((xr + yr) > (r2 * r2))) {
			r = r1 + r2;
			r = r * r;
			// 알고리즘 가동
			if ((xr + yr) > r)
				cout << 0 << endl;
			else if ((xr + yr) == r)
				cout << 1 << endl;
			else cout << 2 << endl;
		}
		else {
			r = r1 - r2;
			r = r * r;

			// 알고리즘 가동
			if ((xr + yr) < r)
				cout << 0 << endl;
			else if ((xr + yr) == r) {
				if ((x1 == x2) && (y1 == y2))
					cout << -1 << endl;
				else cout << 1 << endl;
			}
			else
				cout << 2 << endl;
		}
	}
}