/// 5532.¹æÇĞ ¼÷Á¦

#include <iostream>

#define endl '\n'
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int k = (a - 1) / c + 1;
	int m = (b - 1) / d + 1;
	cout << l - MAX(k, m) << endl;
}