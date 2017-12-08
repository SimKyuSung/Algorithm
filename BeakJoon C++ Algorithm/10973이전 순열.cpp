/// 10973이전 순열

#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)		cin >> a[i];
	int s = n - 1, e = n - 1;
	while (s && a[s] > a[s - 1]) s--;
	if (s == 0) {
		cout << -1;
		return 0;
	}
	while (a[s - 1] < a[e])		 e--;
	a[s - 1] ^= a[e];
	a[e] ^= a[s - 1];
	a[s - 1] ^= a[e];
	for (int i = 0; i < s; i++)		cout << a[i] << " ";
	for (int i = n - 1; i >= s; i--)cout << a[i] << " ";

}