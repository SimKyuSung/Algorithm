/// 5557.1ÇÐ³â

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <size_t> dp1(21, 0);
vector <size_t> dp2(21, 0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, a;
	cin >> n >> a;
	dp1[a] = 1;
	n--;
	while (--n) {
		cin >> a;
		for (int i = a; i <= 20; i++)
			dp2[i] += dp1[i - a];
		for (int i = 0; i <= 20 - a; i++)
			dp2[i] += dp1[i + a];

		for (int i = 0; i <= 20; i++) {
			dp1[i] = dp2[i];
			dp2[i] = 0;
		}
	}
	cin >> a;
	cout << dp1[a] << endl;
}