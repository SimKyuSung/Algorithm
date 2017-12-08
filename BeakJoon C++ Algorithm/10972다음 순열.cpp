/// 10972다음 순열

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a(10000);

int main()
{
	ios::sync_with_stdio(false);
	int n;						cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int s = n - 1, e;
	while (s > 0 && a[s] <= a[s - 1])	s--;
	if (s == 0) {
		cout << -1 << endl;
		return 0;
	}
	while (a[e] < a[s - 1])				e--;
	a[s - 1] ^= a[e];
	a[e] ^= a[s - 1];
	a[s - 1] ^= a[e];
	//reverse(a.begin() + s, a.begin() + n);
	for (int i = 0; i < s; i++)			cout << a[i] << " ";
	for (int i = n - 1; i >= s; i--)	cout << a[i] << " ";
}