/// 13701중복 제거

#include <iostream>
#include <bitset>

using namespace std;

bitset <33554432> b(false);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a;
	while (cin >> a) {
		if (!b[a]) cout << a << " ";
		b[a] = true;
	}
}