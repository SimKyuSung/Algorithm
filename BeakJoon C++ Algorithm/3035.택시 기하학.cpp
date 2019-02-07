/// 3035.택시 기하학

#include <iostream>

#define endl '\n'

using namespace std;

const double pi = 3.1415926535897932384626433832795;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r;
	cin >> r;

	cout.precision(6);
	cout.setf(ios::fixed);
	cout << pi * r * r << endl;
	cout << r * r * 2 << endl;
}