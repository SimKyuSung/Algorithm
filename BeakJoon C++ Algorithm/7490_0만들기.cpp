/// 7490_0¸¸µé±â

#include <iostream>
#include <vector>

using namespace std;

int n;
vector <char> op(8);
void solve(int, int, int);

int main()
{
	int t;	cin >> t;
	while (t--) {
		cin >> n;
		solve(1, 1, 0);
		cout << endl;
	}
}

void solve(int x, int f, int sum) {
	if (x == n) {
		if (sum + f == 0) {
			cout << 1;
			for (int i = 1; i < n; i++)
				cout << op[i - 1] << i + 1;
			cout << "\n";
		}
		return;
	}
	// ' ' 
	op[x - 1] = ' ';
	if (f < 0)		solve(x + 1, f * 10 - x - 1, sum);
	else			solve(x + 1, f * 10 + x + 1, sum);
	// +
	op[x - 1] = '+';
	solve(x + 1, x + 1, sum + f);

	// -
	op[x - 1] = '-';
	solve(x + 1, - x - 1, sum + f);

	return;
}