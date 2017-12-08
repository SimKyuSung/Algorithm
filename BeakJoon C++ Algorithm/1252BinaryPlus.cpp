// 1252BinaryPlus

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	string line1, line2;
	vector <int> p1(82, 0), p2(82, 0), ans(82, 0);
	cin >> line1 >> line2;
	
	reverse(line1.begin(), line1.end());
	reverse(line2.begin(), line2.end());

	for (int i = 0; i < line1.length(); i++) p1[i] = line1[i] - '0';
	for (int i = 0; i < line2.length(); i++) p2[i] = line2[i] - '0';
	

	// carry
	for (int i = 0; i < 82; i++) {
		int now = ans[i] + p1[i] + p2[i];
		if (now == 3) {
			ans[i] = 1;
			ans[i + 1] = 1;
		}
		else if (now == 2) {
			ans[i] = 0;
			ans[i + 1] = 1;
		}
		else if (now == 1) {
			ans[i] = 1;
		}
	}

	/*cout << line1 << " " << line2;*/
	while (ans.size() > 1)
		if (ans.back() == 0)	ans.pop_back();
		else					break;

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)	printf("%d", ans[i]);

}