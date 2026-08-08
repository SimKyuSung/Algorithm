/// 9084µ¿Àü

#include <iostream>
#include <vector>

using namespace std;

vector <int> a;
vector <int> pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;

		a.clear();
		a.resize(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		cin >> m;
		pos.clear();
		pos.resize(m + 1, 0);
		pos[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= m; j++) {
				pos[j] += pos[j - a[i]];
			}
		}
		cout << pos[m] << "\n";
	}

}