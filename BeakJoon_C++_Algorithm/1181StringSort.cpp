// 1181StringSort

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector <string> word[51];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string line;
	while (n--) {
		cin >> line;
		word[line.length()].push_back(line);
	}
	for (int i = 1; i < 51; i++)
		sort(word[i].begin(), word[i].end());
	for (int i = 1; i < 51; i++) {
		if (word[i].size() > 1)
			for (int j = 0; j < word[i].size() - 1; j++)
				if (word[i][j] != word[i][j + 1])
					cout << word[i][j] << '\n';
		if (!word[i].empty())
			cout << word[i].back() << '\n';
	}

}