/// 1373_2진수 8진수

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <int> o;

int main()
{
	string b;
	cin >> b;

	for (int i = b.length() - 1; i > -1;) {
		int j = 0;
		int two = 1;
		int output = 0;
		while (j < 3 && i > -1) {
			output += two * (b[i] == '1');
			j++;
			two *= 2;
			i--;
		}
		o.push(output);
	}

	while (!o.empty()) {
		cout << o.top();
		o.pop();
	}
	cout << endl;

	return 0;
}