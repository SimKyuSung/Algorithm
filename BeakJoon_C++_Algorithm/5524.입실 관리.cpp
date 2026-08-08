/// 5524입실 관리

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string line;
		cin >> line;

		for (int i = 0; i < line.length(); i++)
			if (line[i] <= 'Z')
				line[i] += 32;
		cout << line << "\n";
	}
}