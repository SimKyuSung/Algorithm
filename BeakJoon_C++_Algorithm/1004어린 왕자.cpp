/// 1004어린 왕자

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		// start, end
		int x1, y1, x2, y2;
		// 0 < n < 51
		int n;
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int cx, cy, r;
			int systemIn = 0;
			cin >> cx >> cy >> r;
			// 행성계 내부에 있는지 판별
			if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r)
				systemIn--;
			if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r)
				systemIn++;
			if (systemIn != 0)
				ans++;
		}
		cout << ans << endl;
	}
}

/*

시점과 종점이 같은 항성계에 있는지 다른 항성계에 있는지 판별한다.
-1 : 시점만 항성계에 속함
+1 : 종점만 항성계에 속함
0 : 둘다 속하거나 둘다 속하지 않음

*/