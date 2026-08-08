/// 1019BookPage  <- 11170_0의 개수

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> ans(10, 0);
	vector<int> cy;
	cin >> n;

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
	for (int i = 0; i < 10; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

/*

1	0 1 0 0 0 0 0 0 0 0
2	0 1 1 0 0 0 0 0 0 0
3	0 1 1 1 0 0 0 0 0 0
4	0 1 1 1 1 0 0 0 0 0
5	0 1 1 1 1 1 0 0 0 0
6	0 1 1 1 1 1 1 0 0 0
7	0 1 1 1 1 1 1 1 0 0
8	0 1 1 1 1 1 1 1 1 0
9	0 1 1 1 1 1 1 1 1 1
10	1 2 1 1 1 1 1 1 1 1
11	1 4 1 1 1 1 1 1 1 1
12	1 5 2 1 1 1 1 1 1 1
13	1 6 2 2 1 1 1 1 1 1
14	1 7 2 2 2 1 1 1 1 1
15	1 8 2 2 2 2 1 1 1 1
16	1 9 2 2 2 2 2 1 1 1
17	1 10 2 2 2 2 2 2 1 1
18	1 11 2 2 2 2 2 2 2 1
19	1 12 2 2 2 2 2 2 2 2
20	2 12 3 2 2 2 2 2 2 2
21	2 13 4 2 2 2 2 2 2 2
22	2 13 6 2 2 2 2 2 2 2
23	2 13 7 3 2 2 2 2 2 2
24	2 13 8 3 3 2 2 2 2 2
25	2 13 9 3 3 3 2 2 2 2
26	2 13 10 3 3 3 3 2 2 2
27	2 13 11 3 3 3 3 3 2 2
28	2 13 12 3 3 3 3 3 3 2
29	2 13 13 3 3 3 3 3 3 3
30	3 13 13 4 3 3 3 3 3 3
31	3 14 13 5 3 3 3 3 3 3
32	3 14 14 6 3 3 3 3 3 3

*/