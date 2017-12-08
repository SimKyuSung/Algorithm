/// 2012등수 매기기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <long long> num;

int main()
{
	ios::sync_with_stdio(false);
	// cin.tie(0);
	long long n;
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++)	cin >> num[i];
	sort(num.begin(), num.end());
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += abs(num[i - 1] - i);
	cout << ans;
}

/*

int 형 안에서 해결 할 수 없는 문제인가?

input
n = 500,000
p[i] = {1, 1, ..., 1} 

output
0, 1, 2, ... 499,999

-> 등차수열의 합

ans = 499999 * 500000 / 2 = 124,999,750,000
				int			  2,147,483,647
				unsigned int  4,294,967,295
*/