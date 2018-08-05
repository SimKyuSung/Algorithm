/// 9933.민균이의 비밀번호

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

string txtFile[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = 0, password = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> txtFile[i];
		int s = txtFile[i].size();
		
		for (int j = 0; j <= i; j++) {
			if (txtFile[j].size() == s) {
				bool flag = true;
				for (int k = 0; k < s; k++) {
					if (txtFile[j][k] != txtFile[i][s - k - 1]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ans = s;
					password = txtFile[i][s / 2];
					break;
				}
			}
		}

	}
	cout << ans << ' ' << char(password) << endl;
}