/// 10757큰수 A+B

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const size_t mod = 10;

string a, b;
vector <int> c;

int main()
{
	cin >> a >> b;

	// 항상 a가 더크당
	if (a.size() < b.size())	swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		c.push_back(carry + a[i] - '0');
		if		(i < b.size())		c.back() += b[i] - '0';
		if (c.back() >= mod) {
			carry = 1;
			c.back() %= mod;
		}
		else	carry = 0;
	}
	if (carry) c.push_back(1);
	reverse(c.begin(), c.end());
	for (int i : c)
		cout << i;
}