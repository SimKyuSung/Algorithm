/// 1431.시리얼 번호

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool cmp(string &a, string &b) {
	if (a.size() < b.size())
		return true;
	else if (a.size() == b.size()) {
		int num1 = 0, num2 = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] <= '9')
				num1 += a[i] - '0';
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] <= '9')
				num2 += b[i] - '0';
		}
		if (num1 < num2)
			return true;
		else if (num1 == num2)
			return a < b;
		return false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <string> guitar(n);
	for (int i = 0; i < n; i++)
		cin >> guitar[i];

	sort(guitar.begin(), guitar.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << guitar[i] << endl;
}