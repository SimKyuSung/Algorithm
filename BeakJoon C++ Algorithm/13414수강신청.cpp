/// 13414수강신청

#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>

using namespace std;

int num[500000];
vector <int> ans;
bitset<100000000> stuNum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, l;

	cin >> k >> l;
	for (int i = 0; i < l; i++)
		cin >> num[i];

	for (int i = l - 1; i > -1; i--) {
		if (!stuNum[num[i]]) {
			stuNum[num[i]] = true;
			ans.push_back(num[i]);
		}
	}
	int i = ans.size() - 1;
	while (k-- && i > -1)
		cout << setw(8) << setfill('0') << ans[i--] << "\n";
}