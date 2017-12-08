/// 1004� ����

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
			// �༺�� ���ο� �ִ��� �Ǻ�
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

������ ������ ���� �׼��迡 �ִ��� �ٸ� �׼��迡 �ִ��� �Ǻ��Ѵ�.
-1 : ������ �׼��迡 ����
+1 : ������ �׼��迡 ����
0 : �Ѵ� ���ϰų� �Ѵ� ������ ����

*/