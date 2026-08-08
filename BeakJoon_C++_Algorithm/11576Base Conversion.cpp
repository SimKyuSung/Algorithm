/// 11576Base Conversion

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <int> num;

vector <int> baseConversio(long long n, int base);

int main()
{
	long long a;
	int b;
	cin >> a >> b;

	int m;
	cin >> m;
	
	while (m--) {
		int x;	cin >> x;
		num.push_back(x);
	}

	long long base10 = 0;
	long long baseA = 1;
	while (!num.empty()) {
		base10 += num[num.size() - 1] * baseA;
		num.pop_back();
		baseA *= a;
	}
	num = baseConversio(base10, b);
	while (!num.empty()) {
		cout << num.back() << " ";
		num.pop_back();
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