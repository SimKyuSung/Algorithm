/// 12813이진수 연산

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <bool> a;
vector <bool> b;

int main()
{
	string line;
	cin >> line;
	int n = line.length(), i;
	a.resize(n);
	b.resize(n);
	for (i = 0; i < n; i++)	a[i] = line[i] - '0';
	cin >> line;
	for (i = 0; i < n; i++)	b[i] = line[i] - '0';
	// and &
	for (i = 0; i < n; i++) cout << (a[i] & b[i]);
	cout << "\n";
	// or  |
	for (i = 0; i < n; i++) cout << (a[i] | b[i]);
	cout << "\n";
	// xor ^
	for (i = 0; i < n; i++) cout << (a[i] ^ b[i]);
	cout << "\n";
	// not a !
	for (i = 0; i < n; i++) cout << (!a[i]);
	cout << "\n";
	// not b !
	for (i = 0; i < n; i++) cout << (!b[i]);
	cout << "\n";
}