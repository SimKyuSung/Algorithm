/// 15707.exceed or not

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const size_t MAX = ((size_t)-1 >> 1);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	size_t r;
	cin >> a >> b >> r;
	if (a[0] == '0' || b[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	if (a.size() > 18 || b.size() > 18) {
		cout << "overflow" << endl;
		return 0;
	}

	size_t ia = 0, ib = 0;
	for (auto s : a) {
		ia *= 10;
		ia += (s - '0');
	}
	for (auto s : b) {
		ib *= 10;
		ib += (s - '0');
	}
	if (ia > r || ib > r) {
		cout << "overflow" << endl;
		return 0;
	}

	if (ia < ib) {
		ia ^= ib;
		ib ^= ia;
		ia ^= ib;
	}
	if (ia > r / ib) {
		cout << "overflow" << endl;
	}
	else {
		cout << ia * ib << endl;
	}
	return 0;
}


/*

if (a * b > r)
	cout << "overflow" << endl;
else
	cout << a * b << endl;

a > (r - mod) / b;

*/