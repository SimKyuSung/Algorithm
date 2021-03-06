/// 1213. [S/W 문제해결 기본] 3일차 - String

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string);
vector<int> kmp(string s, string p);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;

	for (int t = 1; t <= testCase; t++) {
		int n;
		string f, s;

		cin >> n >> f >> s;


		cout << '#' << t << ' ' << kmp(s, f).size() << '\n';
	}
}

vector<int> getPi(string p) { 
	int m = (int)p.size(), j = 0; 
	vector<int> pi(m, 0); 
	for (int i = 1; i < m; i++) { 
		while (j > 0 && p[i] != p[j]) 
			j = pi[j - 1]; 
		if (p[i] == p[j]) 
			pi[i] = ++j; 
	} 
	return pi; 
}

vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}