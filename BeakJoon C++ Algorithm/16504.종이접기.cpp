/// 16504.종이접기

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, input;
	size_t ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			ans += input;
		}
	}
	cout << ans << endl;
}