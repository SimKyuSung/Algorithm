// 14561È¸¹®

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> baseConversio(long long n, int base);

int main()
{
	ios::sync_with_stdio(false);
	int t;	cin >> t;
	while (t--) {
		long long n;
		int b;	cin >> n >> b;
		vector <int> num = baseConversio(n, b);
		bool isPalin = true;
		n = num.size();
		for (int i = 0; i < n / 2; i++)
			if (num[i] != num[n - 1 - i]) isPalin = false;
		cout << isPalin << endl;
	}
}

vector <int> baseConversio(long long n, int base) {
	vector <int> ans;
	while (n > 0) {
		ans.push_back(n % base);
		n /= base;
	}
	return ans;
}