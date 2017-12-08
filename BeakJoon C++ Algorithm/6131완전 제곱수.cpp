/// 6131완전 제곱수

#include <iostream>

using namespace std;

const int maxNum = 250001;
bool num[maxNum] = { false, };

int main()
{
	int n;	cin >> n;
	for (int i = 1; i < 501; i++)
		num[i * i] = true;

	int ans = 0;
	for (int i = n; i < maxNum; i++)
		if (num[i] && num[i - n])
			ans++;
	cout << ans << endl;

}