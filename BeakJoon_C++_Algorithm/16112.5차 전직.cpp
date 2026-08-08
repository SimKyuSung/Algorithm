/// 16112.5Â÷ ÀüÁ÷

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> quest;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	quest.resize(n);

	for (auto &q : quest)
		cin >> q;
	sort(quest.begin(), quest.end());

	long long ans = 0, size = 1;

	for (int i = 1; i < n; i++) {
		ans += size * quest[i];
		size++;
		if (size > k)
			size = k;
	}
	cout << ans << endl;
}