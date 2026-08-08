/// 3460ÀÌÁø¼ö

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		int ans = 0;
		while (n) {
			if (n & 1)	printf("%d ", ans);
			ans++;
			n >>= 1;
		}
	}

}