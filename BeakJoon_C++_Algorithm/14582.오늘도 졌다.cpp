/// 14582.¿À´Ãµµ Á³´Ù

#include<iostream>

using namespace std;

int i, asum, bsum, f, a[10], b[10];

int main()
{
	for (i = 0; i < 9; i++)
		cin >> a[i];
	for (i = 0; i < 9; i++)
		cin >> b[i];
	for (i = 0; i < 9; i++) {
		asum += a[i];
		if (asum > bsum)
			f = 1;
		bsum += b[i];
	}
	if (f == 1 && bsum > asum)
		cout << "Yes\n";
	else
		cout << "No\n";
}