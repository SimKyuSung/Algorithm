/// 1422.숫자의 신

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define endl '\n'

using namespace std;

vector <string> num;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, n, godNum = 0;
	long long maxNum = 0;

	cin >> k >> n;
	num.resize(k);

	for (auto &a : num)
		cin >> a;
	sort(num.begin(), num.end(), cmp);

	for (int i = 0; i < k; i++) {
		long long x = 0;
		for (auto aNum : num[i]) {
			x *= 10;
			x += aNum - '0';
		}
		if (maxNum <= x) {
			maxNum = x;
			godNum = i;
		}
	}
	
	for (int i = 0; i < k; i++) {
		if (godNum == i) {
			for (int j = 0; j < n - k; j++)
				cout << num[i];
		}
		cout << num[i];
	}
	cout << endl;
}

/*


3 4
9
77
3

977773


4 5
9
77
3
3

2 3
75
75123

*/