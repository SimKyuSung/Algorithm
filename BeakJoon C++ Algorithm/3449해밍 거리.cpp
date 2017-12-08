/// 3449해밍 거리

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string c[2];
		cin >> c[0] >> c[1];
		int counter = 0;
		for (int i = 0; i < c[0].length(); i++)
			if (c[0][i] != c[1][i])
				counter++;
		cout << "Hamming distance is " << counter << ".\n";
	}
}