/// 2879.�ڵ��� ���ڰ�

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <long long> x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	x.resize(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	long long move = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		long long hall;
		cin >> hall;

		// ��ǥ���� ���� ������
		if (move + x[i] > hall) {
			// ���ڶ� ������
			if (move < 0) {
				ans += move + x[i] - hall;
				move = hall - x[i];
			}
			// �Ųٷ� ������
			else {
				move = hall - x[i];
				if (move < 0)
					ans -= move;
			}
		}
		// ��ǥ���� �Ʒ� ������
		else if (move + x[i] < hall) {
			// ���ڶ� ������
			if (move > 0) {
				ans += hall - (x[i] + move);
				move = hall - x[i];
			}
			// �Ųٷ� ������
			else {
				move = hall - x[i];
				if (move > 0)
					ans += move;
			}
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}