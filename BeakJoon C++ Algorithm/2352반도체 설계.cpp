/// 2352반도체 설계

#include <iostream>
#include <algorithm>

using namespace std;

int se[40004];
int lis[40004];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> se[i];
	
	int pLis = 0;
	lis[0] = se[0];
	for (int i = 1; i < n; i++) {
		if (se[i] > lis[pLis])
			lis[++pLis] = se[i];
		else {
			int left = 0;
			int right = pLis;
			while (left < right) {
				int mid = (left + right) / 2;
				if (lis[mid] >= se[i])	right = mid;
				else					left = mid + 1;
			}
			lis[right] = se[i];
		}
	}
	cout << pLis + 1<< endl;
}