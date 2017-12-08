// 10214Win

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		vector<int> yonsei(9);
		vector<int> korea(9);
		int y = 0, k = 0;
		for (int i = 0; i < 9; i++) {
			cin >> yonsei[i] >> korea[i];
			y += yonsei[i];
			k += korea[i];
		}
		if (y == k)		cout << "Draw\n";
		else if (y > k)	cout << "Yonsei\n";
		else			cout << "korea\n";
	}
}