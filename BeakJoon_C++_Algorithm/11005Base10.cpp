// 11005Base10

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <char> baseConversio(int n, int base);

int main()
{
	ios::sync_with_stdio(false);
	int n, b;	cin >> n >> b;
	vector <char> base = baseConversio(n, b);
	while (!base.empty()) {
		printf("%c", base.back());
		base.pop_back();
	}
	printf("\n");
}

vector <char> baseConversio(int n, int base) {
	vector <char> ans;
	while (n > 0) {
		int x = n % base;
		char c;
		if (x < 10)	c = x + '0';
		else		c = x - 10 + 'A';
		ans.push_back(c);
		n /= base;
	}
	return ans;
}