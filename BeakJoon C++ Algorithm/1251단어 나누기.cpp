/// 1251�ܾ� ������

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string word, ans = "";
	ans.append(50, 'z');
	cin >> word;
	int n = word.length();
	for (int i = 1; i < n - 1; i++) {
		// 1. �ϴ� ������
		reverse(word.begin(), word.begin() + i);
		for (int j = i + 1; j < n; j++) {
			reverse(word.begin() + i, word.begin() + j);
			reverse(word.begin() + j, word.end());
			// 2. ���ϰ�
			if (word.compare(ans) < 0)	ans = word;
			// 3. ���󺹱�
			reverse(word.begin() + i, word.begin() + j);
			reverse(word.begin() + j, word.end());

		}
		reverse(word.begin(), word.begin() + i);
	}
	cout << ans << endl;
}

/*
6
016
026
036
046
056

126
136
146
156

236
246
256

346
356

456

*/