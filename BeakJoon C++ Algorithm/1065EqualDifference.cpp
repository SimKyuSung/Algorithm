#include <iostream>

using namespace std;

int main()
{
	int N;
	int ans = 0;
	int d;
	cin >> N;
	// ���������� �����ϴ� ����
	for (int i = N; i > 0; i--) {
		// 100�̸��� ��� ���� ����
		if (i < 100)
			ans++;
		else {	// �� �ڸ� ���� ���̸� ��
			d = (i / 100) - ((i / 10) % 10);
			if (d == (i / 10) % 10 - (i % 10))
				ans++;
		}
	}
	cout << ans << "\n";
}