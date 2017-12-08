/// 14646욱제는 결정장애야!!

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <bool> c;

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;

	c.resize(n, false);
	int input, counter = 0;
	int ans = 0;
	for (int i = 0; i < n * 2; i++) {
		cin >> input;
		if (c[input - 1])	counter--;
		else {
			c[input - 1] = true;
			counter++;
		}
		ans = max(ans, counter);
	}
	cout << ans << endl;

}