// 14656������ ����Ʈ��!!

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, num;	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (num != i)	ans++;
	}
	cout << ans;
}