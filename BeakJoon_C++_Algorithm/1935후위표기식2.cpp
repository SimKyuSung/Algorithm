/// 1935후위표기식2

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector <double> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string line;
	cin >> n >> line;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	stack <double> s;
	for (int i = 0; i < line.length(); i++) {
		if ('A' <= line[i])
			s.push(a[line[i] - 'A']);
		else {
			char op = line[i];
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			if (op == '+')		num1 += num2;
			else if (op == '-') num1 -= num2;
			else if (op == '*') num1 *= num2;
			else if (op == '/') num1 /= num2;
			s.push(num1);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}

/*
5
ABC*+DE/-
1
2
3
4
5


6
AB*C+D-E+F*
1
2
3
4
5
6

36.00

*/