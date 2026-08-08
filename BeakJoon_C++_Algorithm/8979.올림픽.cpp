/// 8979.¿Ã¸²ÇÈ

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

struct Score {
	int id, g, s, c;
};

bool cmp(Score &a, Score &b) {
	if (a.g > b.g)	return true;
	else if (a.g == b.g) {
		if (a.s > b.s)	return true;
		else if (a.s == b.s) {
			return a.c > b.c;
		}
		return false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector <Score> score(n);
	for (int i = 0; i < n; i++)
		cin >> score[i].id >> score[i].g >> score[i].s >> score[i].c;
	sort(score.begin(), score.end(), cmp);

	//for (int i = 0; i < n; i++)
	//	cout << score[i].id << ' ';
	//cout << endl;
	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (score[i].id == k) {
			cout << rank << endl;
			return 0;
		}
		if (score[i].g != score[i + 1].g ||
			score[i].s != score[i + 1].s ||
			score[i].c != score[i + 1].c)
			rank = i + 2;
	}
}