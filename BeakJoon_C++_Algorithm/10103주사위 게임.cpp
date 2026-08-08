/// 10103주사위 게임

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int a = 100, b = 100;
	cin >> n;
	while (n--) {
		int aa, bb;
		cin >> aa >> bb;
		if		(aa > bb) b -= aa;
		else if (bb > aa) a -= bb;
	}
	cout << a << "\n" << b;
}