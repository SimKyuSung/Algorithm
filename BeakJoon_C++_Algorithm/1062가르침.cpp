/// 1062°¡¸£Ä§

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;


int n, k;
vector <bitset <26>> a;
int ans = 0;
void teach(int, int, bitset<26>);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		for (int j = 0; j < word.length(); j++)
			a[i][word[j] - 'a'] = true;
	}
	bitset<26> kk;
	kk[0] = true;
	teach(1, 1, kk);
	cout << ans;
}

void teach(int index, int counter, bitset<26> kk) {
	if (counter > k) return;

	if (counter == k) {
		int tmpAns = 0;
		for (int i = 0; i < n; i++)
			tmpAns += (a[i] == (a[i] & kk));
		ans = max(ans, tmpAns);
	}
	if (index >= 26) return;
	if (index == 'c' - 'a' || index == 'i' - 'a' || index == 'n' - 'a' || index == 't' - 'a') {
		kk[index] = true;
		teach(index + 1, counter + 1, kk);
		return;
	}
	teach(index + 1, counter, kk);
	kk[index] = true;
	teach(index + 1, counter + 1, kk);
}

/*
3 6
anta rc tica
anta hello tica
anta car tica

a
c
i
n
t
+-5

a c     i   n    r t
abcdefghijklnmopqrstuvwxyz

*/