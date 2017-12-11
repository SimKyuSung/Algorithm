/// 1036_36진수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > base36, base36sum(35);
vector <int> ans, ch(36);

bool cmp(vector <int>, vector <int>);

int main()
{
	/* 1. init, input */
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 36; i++)
		ch[i] = i;
	int n, k, mSize = 0;
	string tmp;
	cin >> n;
	base36.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		mSize = max(mSize, (int)tmp.length());
		if (tmp.length() == 1 && tmp[0] == '0')
			continue;
		while (!tmp.empty()) {
			int x = tmp.back();
			if ('0' <= x && x <= '9')	x -= '0';
			else 						x -= 'A' - 10;
			base36[i].push_back(x);
			tmp.pop_back();
		}
	}

	/* 2. 0 ~ 35를 35로 바꾼뒤 합계 */
	for (int b = 0; b < 35; b++) {
		int sum, carry = 0;
		for (int j = 0; j < mSize; j++) {
			sum = carry;
			for (int i = 0; i < n; i++) {
				if (j < base36[i].size()) {
					if (base36[i][j] == b)
						sum += 35;
					else
						sum += base36[i][j];
				}
			}
			base36sum[b].push_back(sum % 36);
			carry = sum / 36;
		}
		while (carry) {
			base36sum[b].push_back(carry % 36);
			carry /= 36;
		}
	}

	/* 3. 합계 소팅*/
	for (int i = 0; i < 34; i++) {
		int tmp = i;
		for (int j = i + 1; j < 35; j++) {
			if (cmp(base36sum[tmp], base36sum[j]))
				tmp = j;
		}
		swap(ch[i], ch[tmp]);
		swap(base36sum[i], base36sum[tmp]);
	}

	/* 4. 상위 k개 바꾸기 */
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < base36[i].size(); j++)
			for (int b = 0; b < k; b++)
				if (base36[i][j] == ch[b])
					base36[i][j] = 35;
	}

	/* 5. 바꾼뒤 합계 구하기 */
	vector <int> ans;
	int sum, carry = 0;
	for (int j = 0; j < mSize; j++) {
		sum = carry;
		for (int i = 0; i < n; i++) {
			if (j < base36[i].size())
				sum += base36[i][j];
		}
		ans.push_back(sum % 36);
		carry = sum / 36;
	}
	while (carry) {
		ans.push_back(carry % 36);
		carry /= 36;
	}

	while (!ans.empty()) {
		if (ans.back() > 9) cout << char(ans.back() - 10 + 'A');
		else				cout << ans.back();
		ans.pop_back();
	}
	cout << endl;
}

bool cmp(vector <int> a, vector <int> b) {
	// b가 더 크면 return true;
	if (a.size() != b.size())
		return a.size() < b.size();

	for (int i = b.size() - 1; i >= 0; i--) {
		if (a[i] != b[i])
			return a[i] < b[i];
	}
	return true;
}