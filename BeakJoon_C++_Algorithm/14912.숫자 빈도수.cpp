/// 14912.숫자 빈도수
/// 1019BookPage  <- 11170_0의 개수

#include <iostream>
#include <cstdio>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	int n, d;
	vector<int> ans(10, 0);
	vector<int> cy;
	cin >> n >> d;

	// 각 자리수 수집
	int tmp = n;
	while (tmp) {
		cy.push_back(tmp % 10);
		tmp /= 10;
	}

	for (int i = 0, ten = 1; i < cy.size(); i += 1, ten *= 10) {
		for (int j = 0; j < cy[i]; j++)
			ans[j] += ten;
		ans[cy[i]]++;
		for (int j = i + 1; j < cy.size(); j++)
			ans[cy[j]] += cy[i] * ten;
		for (int k = 0; k < i; k++)
			for (int j = 0; j < 10; j++)
				ans[j] += ten / 10 * cy[i];
		ans[0] -= ten;
	}

	// output
	cout << ans[d] << endl;
}