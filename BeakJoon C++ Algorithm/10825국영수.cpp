/// 10825±¹¿µ¼ö

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Score
{
	int kor, eng, mat;
	string name;
};

vector<Score> s;
bool cmp(Score x, Score y) {
	if (x.kor != y.kor) return x.kor > y.kor;
	if (x.eng != y.eng) return x.eng < y.eng;
	if (x.mat != y.mat) return x.mat > y.mat;
	return x.name < y.name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].mat;
	sort(s.begin(), s.end(), cmp);
	for (auto name : s)
		cout << name.name << '\n';
}