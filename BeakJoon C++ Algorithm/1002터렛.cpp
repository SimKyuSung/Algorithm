/// 1002�ͷ�

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

	// ��� ���е��� ���ؼ� ��Ʈ ������
	for (int i = 0; i < n; i++) {
		// �ԏ��ޱ�!
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		xr = x1 - x2;
		yr = y1 - y2;
		// �Ǵ� math.h �� pow �Լ� ���
		xr = xr * xr;
		yr = yr * yr;

		// �� ���� �ܺο� ���� ���, ������ ���� ��� ��������
		if (((xr + yr) > (r1 * r1)) && ((xr + yr) > (r2 * r2))) {
			r = r1 + r2;
			r = r * r;
			// �˰��� ����
			if ((xr + yr) > r)
				cout << 0 << endl;
			else if ((xr + yr) == r)
				cout << 1 << endl;
			else cout << 2 << endl;
		}
		else {
			r = r1 - r2;
			r = r * r;

			// �˰��� ����
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