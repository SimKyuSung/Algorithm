// 1145LCM

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int, int);
int lcm(int, int);
int combination(int, int);
int minLCM(int, int, int);

int arr[5];

int main() {
	ios::sync_with_stdio(false);
	int t = 5;
	while (t--)		cin >> arr[t];
	// 5C2 = 10
	cout << combination(5, 3);
}

int gcd(int n, int m) {
	int r;
	while (true) {
		r = m % n;
		if (r == 0)
			return n;
		else {
			m = n;
			n = r;
		}
	}
}

int lcm(int n, int m) {
	return n * m / gcd(n, m);
}

int combination(int n, int r) {
	int ans = 0x7fffffff;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				ans = min(ans, minLCM(arr[i], arr[j], arr[k]));
	return ans;
}
int minLCM(int a, int b, int c) {
	return lcm(a, lcm(b, c));
}