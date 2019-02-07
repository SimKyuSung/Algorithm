/// 3054.피터팬 프레임

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const string pf1 = "..#.";
const string pf2 = ".#.#";
string pf3 = "#...";

const string wf1 = "..*.";
const string wf2 = ".*.*";
string wf3 = "*...";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string d;
	cin >> d;

	int n = d.size();

	for (int i = 0; i < n; i++)
		if ((i + 1) % 3)
			cout << pf1;
		else
			cout << wf1;
	cout << '.';
	cout << endl;

	for (int i = 0; i < n; i++)
		if ((i + 1) % 3)
			cout << pf2;
		else
			cout << wf2;
	cout << '.';
	cout << endl;

	for (int i = 0; i < n; i++) {
		pf3[2] = wf3[2] = d[i];
		if ((i + 1) % 3) {
			cout << pf3;
			pf3[0] = '#';
		}
		else {
			cout << wf3;
			pf3[0] = '*';
		}
	}
	cout << ((n % 3) ? '#' : '*');
	cout << endl;

	for (int i = 0; i < n; i++)
		if ((i + 1) % 3)
			cout << pf2;
		else
			cout << wf2;
	cout << '.';
	cout << endl;

	for (int i = 0; i < n; i++)
		if ((i + 1) % 3)
			cout << pf1;
		else
			cout << wf1;
	cout << '.';
	cout << endl;


}