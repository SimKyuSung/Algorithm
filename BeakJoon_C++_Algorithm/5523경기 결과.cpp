/// 5523경기 결과

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a = 0, b = 0;
	while (n--) {
		int ai, bi;
		cin >> ai >> bi;
		if		(ai > bi) a++;
		else if (ai < bi) b++;
	}
	cout << a << " " << b << '\n';
}