/// 11052ºØ¾î»§ ÆÇ¸ÅÇÏ±â

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		for (int j = 0; j < i; j++)
			p[i] = max(p[i], p[i - j - 1] + p[j]);
	}
	cout << p.back();
}


/*

1  2  3  4  5  6  7  8  9
   11 12 13 14
      21 22 23
         31 32
		    41

11 12

*/