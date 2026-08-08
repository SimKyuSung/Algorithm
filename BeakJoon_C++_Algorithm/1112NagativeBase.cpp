// 1112NagativeBase

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack <int> convert(long long, int);

int main()
{
	long long x;
	int b;
	cin >> x >> b;

	bool nagativeFlag = x < 0 && b > 0;
	if (nagativeFlag)	x = -x;

	stack <int> num = convert(x, b);
	
	if (nagativeFlag)	cout << '-';
	while (!num.empty()) {
		printf("%d", num.top());
		num.pop();
	}
	cout << '\n';
}

stack <int> convert(long long x, int base) {
	stack <int> ans;
	while (x != 0) {
		int s = x % base;
		x /= base;
		if (s < 0) {
			s = s - base;
			x++;
		}
		ans.push(s);
	}
	if (ans.empty())	ans.push(0);
	return ans;
}

/*

+ + -> +
+ - -> +

- + -> -
- - -> +

*/