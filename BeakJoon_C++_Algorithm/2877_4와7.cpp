/// 2877_4¿Í7

#include <iostream>
#include <vector>

using namespace std;

vector <int> ans;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int n;
	cin >> n;
	n++;
	while (n > 1) {
		if (n % 2)    ans.push_back(7);
		else          ans.push_back(4);
		n /= 2;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
}

/*
2    4
3    7

4    44
5    47
6    74
7    77



*/
