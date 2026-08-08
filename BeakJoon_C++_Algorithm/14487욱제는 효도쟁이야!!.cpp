/// 14487욱제는 효도쟁이야!!

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, v, sum = 0, maximum = 0;
	cin >> n;
	while (n--) {
		cin >> v;
		sum += v;
		maximum = max(maximum, v);
	}
	cout << sum - maximum;
	
}