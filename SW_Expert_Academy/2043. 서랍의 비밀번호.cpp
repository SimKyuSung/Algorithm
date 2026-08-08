/// 2043. 서랍의 비밀번호

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, k, ans;
	cin >> p >> k;
	ans = (p - k + 1);
	cout << (ans) + ((ans < 0) * 1000);
}