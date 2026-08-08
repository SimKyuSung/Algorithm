// 2822Score

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	vector< pair<int, int> > score(8);
	vector<bool> candidate(8, false);
	int total = 0;
	for (int i = 0; i < 8; i++) {
		cin >> score[i].first;
		score[i].second = i;
	}
	sort(score.begin(), score.end());
	for (int i = 3; i < 8; i++) {
		candidate[score[i].second] = true;
		total += score[i].first;
	}
	printf("%d\n", total);
	for (int i = 0; i < 8; i++)
		if (candidate[i])
			printf("%d ", i + 1);
}