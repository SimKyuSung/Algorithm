#include <iostream>>
#include <string>

using namespace std;


int main()
{
	int n;
	string cmd;
	string ans = "";
	int strLen;

	cin >> n;

	// 1�� �Է�
	cin >> cmd;
	ans = cmd;
	strLen = ans.length();

	while (--n) {
		cin >> cmd;
		// ans �� cmd�� �� �Ͽ� �ٸ� �κ� "?" ó��
		for (int i = 0; i < strLen; i++)
			if (cmd[i] != ans[i])
				ans[i] = '?';
	}
	cout << ans << endl;
}