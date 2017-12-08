/// 10864Ä£±¸

#include <iostream>
#include <vector>

using namespace std;

vector <int> f;

int main()
{
	int n, m;	cin >> n >> m;
	f.resize(n, 0);

	for (int i = 0; i < m; i++) {
		int a, b;	cin >> a >> b;
		f[a - 1]++;
		f[b - 1]++;
	}
	for (int i = 0; i < n; i++)
		cout << f[i] << endl;
}