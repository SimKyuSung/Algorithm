/// 1081гу

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int l, u;

	cin >> l >> u;

	vector<int> cy1;
	vector<int> cy2;
	vector<size_t> ans1(10, 0);
	vector<size_t> ans2(10, 0);

	l--;
	if (l == -1) l = 0;
	while (l) {
		cy1.push_back(l % 10);
		l /= 10;
	}
	for (int i = 0, ten = 1; i < cy1.size(); i += 1, ten *= 10) {
		for (int j = 0; j < cy1[i]; j++)
			ans1[j] += ten;
		ans1[cy1[i]]++;
		for (int j = i + 1; j < cy1.size(); j++)
			ans1[cy1[j]] += cy1[i] * ten;
		for (int k = 0; k < i; k++)
			for (int j = 0; j < 10; j++)
				ans1[j] += ten / 10 * cy1[i];
		ans1[0] -= ten;
	}

	while (u) {
		cy2.push_back(u % 10);
		u /= 10;
	}
	for (int i = 0, ten = 1; i < cy2.size(); i += 1, ten *= 10) {
		for (int j = 0; j < cy2[i]; j++)
			ans2[j] += ten;
		ans2[cy2[i]]++;
		for (int j = i + 1; j < cy2.size(); j++)
			ans2[cy2[j]] += cy2[i] * ten;
		for (int k = 0; k < i; k++)
			for (int j = 0; j < 10; j++)
				ans2[j] += ten / 10 * cy2[i];
		ans2[0] -= ten;
	}

	size_t sum = 0;
	for (size_t i = 1; i < 10; i++) {
		sum += (ans2[i] - ans1[i]) * i;
	}

	cout << sum << endl;

}