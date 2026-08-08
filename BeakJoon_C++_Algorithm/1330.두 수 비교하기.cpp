/// 1330.두 수 비교하기

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << '>' << endl;
	else if (a < b)
		cout << '<' << endl;
	else
		cout << "==" << endl;

}