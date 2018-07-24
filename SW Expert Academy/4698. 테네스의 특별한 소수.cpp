/// 4698. 테네스의 특별한 소수

#include <iostream>
#include <vector>
#include <bitset>

#define endl '\n'

using namespace std;

const int n = 1000001;
bitset <n> p;
vector <int> pi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < n; i++) {
		if (!p[i]) {
			pi.push_back(i);
			for (int j = i + i; j < n; j += i)
				p[j] = 1;
		}
	}

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int d, a, b, ans = 0;
		cin >> d >> a >> b;
		for (int i = 0; i < pi.size() && pi[i] <= b; i++) {
			if (a <= pi[i]) {
				int tmp = pi[i];
				while (tmp) {
					if (tmp % 10 == d) {
						ans++;
						break;
					}
					tmp /= 10;
				}
			}
		}

		cout << '#' << t << ' ' << ans << endl;
	}
}