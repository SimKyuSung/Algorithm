/// 6603로또

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> p(13);
vector <int> ans(6);

int l = 6, c;
void solve(int, int);

int main()
{
	while (true) {
		cin >> c;
		if (c == 0)	break;
		for (int i = 0; i < c; i++)	cin >> p[i];
		solve(0, 0);
		cout << endl;
	}
}

void solve(int n, int counter) {
	// 종료 조건 검사
	if (n == l) {
		for (int i = 0; i < l; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = counter; i < c; i++) {
		ans[n] = p[i];
		solve(n + 1, i + 1);
	}
	return;
}