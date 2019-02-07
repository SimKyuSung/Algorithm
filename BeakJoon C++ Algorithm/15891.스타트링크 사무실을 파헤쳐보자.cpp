/// 15891.스타트링크 사무실을 파헤쳐보자

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n, ans = 0;
	cin >> n;
	switch (n)
	{
	case 1:
		ans = 65;
		break;
	case 2:
		ans = 17;
		break;
	case 3:
		ans = 4;
		break;
	case 4:
		ans = 4;
		break;
	case 5:
		ans = 64;
		break;
	}
	cout << ans << endl;
}