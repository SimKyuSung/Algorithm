/// 11948.과목선택

#include <iostream>

#define MIN(a, b) (a)<(b)?(a):(b)
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d, e, f, ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	ans = a + b + c + d + e + f;
	ans -= MIN(MIN(a, b), MIN(c, d));
	ans -= MIN(e, f);
	cout << ans << endl;
}