/// 1234. [S/W �����ذ� �⺻] 10���� - ��й�ȣ

#include <iostream>
#include <string>

using namespace std;

char ans[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	// cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, a = 0;
		string password;
		cin >> n >> password;;

		ans[0] = password[0];
		for (int i = 1; i < n; i++) {
			if (ans[a] != password[i])
				ans[++a] = password[i];
			else
				a--;
		}
		ans[a + 1] = 0;
		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*
�׷�Ÿ!
�����̿��� ���̴�!

*/