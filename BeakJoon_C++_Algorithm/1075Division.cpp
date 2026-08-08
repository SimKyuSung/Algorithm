#include <iostream>

using namespace std;

int main()
{
	int N, F;
	int ans;

	cin >> N >> F;
	N = (N / 100) * 100;
	for (ans = 0; ans < 100; ans++)
		if ((N + ans) % F == 0)
			break;

	if (ans < 10)
		cout << 0;
	cout << ans << endl;
}