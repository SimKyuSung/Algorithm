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

	// 1턴 입력
	cin >> cmd;
	ans = cmd;
	strLen = ans.length();

	while (--n) {
		cin >> cmd;
		// ans 와 cmd와 비교 하여 다른 부분 "?" 처리
		for (int i = 0; i < strLen; i++)
			if (cmd[i] != ans[i])
				ans[i] = '?';
	}
	cout << ans << endl;
}