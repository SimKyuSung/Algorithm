/// 13419ÅÁ¼öÀ°

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		string line;
		cin >> line;
		if (line.length() == 1) {
			cout << line << "\n" << line << "\n";
		}
		else {
			string ans[2] = { "", "" };
			if (line.length() % 2)
				line += line;
			for (int i = 0; i < line.length(); i += 2) {
				ans[0] += line[i];
				ans[1] += line[i + 1];
			}
			cout << ans[0] << "\n" << ans[1] << "\n";
		}
	}
}