// 1225CowMultiplication

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string line1;
	string line2;

	unsigned long long ans = 0;
	cin >> line1 >> line2;
	for (int i = 0; i < line1.length(); i++)
		for (int j = 0; j < line2.length(); j++)
			ans += (line1[i] - '0') * (line2[j] - '0');
	cout << ans << "\n";
}