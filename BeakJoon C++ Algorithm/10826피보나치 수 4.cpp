/// 10826피보나치 수 4

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// 연산 가속을 위해 10억 단위로 끊음
// 10억을 넘어 가면 모듈러 치고 다음 벡터로 push 하고 연산

//////////////////////////// 18446744073709551615
const unsigned long long m = 1000000000000000000;
vector <unsigned long long> a;
vector <unsigned long long> b;
vector <unsigned long long> c;

int main()
{
	int n;
	cin >> n;
	if (n < 2) {
		cout << n;
		return 0;
	}

	a.push_back(1);
	b.push_back(1);
	for (int i = 1; i < n; i++) {
		// c = a + b
		c.resize(b.size());
		int carry = 0;
		for (int v = 0; v < a.size(); v++) {
			c[v] = (carry + a[v] + b[v]) % m;
			if (carry + a[v] + b[v] >= m)	carry = 1;
			else			carry = 0;
		}
		if (a.size() < b.size())	c.back() = b.back() + carry;
		else if (carry)				c.push_back(1);
		a = b;
		b = c;
	}
	cout << a[a.size() - 1];
	cout << setfill('0');
	for (int i = a.size() - 2; i >= 0; i--)
		cout << setw(18) << a[i];
}