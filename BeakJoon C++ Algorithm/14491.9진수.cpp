/// 14491.9����

#include <iostream>

#define endl '\n'

using namespace std;

int stack[7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, i = 0;
	cin >> t;
	while (t) {
		stack[i++] = t % 9;
		t /= 9;
	}
	while (i--)
		cout << stack[i];
	cout << endl;

}

/*

10000

*/