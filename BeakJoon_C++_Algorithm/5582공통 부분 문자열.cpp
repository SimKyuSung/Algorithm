/// 5582공통 부분 문자열

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <int> dp1;
vector <int> dp2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	dp1.resize(b.length(), 0);

	int ans = 0;
	for (int j = 0; j < b.length(); j++) {
		if (a[0] == b[j]) {
			dp1[j] = 1;
			ans = 1;
		}
	}
	for (int i = 1; i < a.length(); i++) {
		dp2 = vector<int>(b.length(), 0);
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp2[j] = 1;
				if (a[i - 1] == b[j - 1])
					dp2[j] = dp1[j - 1] + 1;
			}
			ans = max(dp2[j], ans);
			//cout << dp2[j - 1];
		}
		//cout << dp2.back();
		//cout << endl;
		if (a[i] == b[0]) {
			dp2[0] = 1;
			ans = max(ans, 1);
		}
		dp1 = dp2;
	}
	cout << ans << endl;
}

/*

AAAA
A	1111
A	1222

ECADADABRBCRDARA
A	0010101000000101
B	0000000201000000
R	0000000030010010
A	0010101000000102
C	0100000000100000
A	0020101000000101
D	0003020000001000
A	0010403000000201
B	0000000401000000
R	0000000050010010
A	0010101000000102

5

*/