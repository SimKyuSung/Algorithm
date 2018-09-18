/// 1342.행운의 문자열

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int n;
vector <char> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string input;
	cin >> input;
	n = input.size();

	for (int i = 0; i < n; i++)
		s.push_back(input[i]);
	sort(s.begin(), s.end());

	int ans = 0;
	do {
		bool flag = 1;
		for (int i = 1; i < n; i++)
			if (s[i - 1] == s[i])
				flag = 0;
		ans += flag;
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
}