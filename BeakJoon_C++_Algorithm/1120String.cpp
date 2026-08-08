/// 1120String

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int ans = 50;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int counter = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j])
				counter++;
		}
		ans = min(ans, counter);
	}
	cout << ans;
}