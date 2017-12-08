/// 2407а╤гу

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sys/types.h>

using namespace std;

const size_t mod = 1000000000000000000;

vector < vector <vector <size_t> > > com;

int main()
{
	int n, m;
	cin >> n >> m;
	com.resize(n + 1, vector <vector<size_t> >());
	for (int i = 1; i <= n; i++) {
		com[i].resize(i + 1, vector<size_t>());
		com[i][0].push_back(1);
		com[i][i].push_back(1);
	}
	// 1 2
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			int maxSize = max(com[i - 1][j - 1].size(), com[i - 1][j].size());
			int minSize = min(com[i - 1][j - 1].size(), com[i - 1][j].size());
			com[i][j].resize(maxSize);
			int carry = 0;
			for (int v = 0; v < minSize; v++) {
				com[i][j][v] = carry + com[i - 1][j - 1][v] + com[i - 1][j][v];
				if (com[i][j][v] >= mod) {
					carry = 1;
					com[i][j][v] %= mod;
				}
				else	carry = 0;
			}
			if		(com[i - 1][j - 1].size() < com[i - 1][j].size())	com[i][j].back() = com[i - 1][j].back() + carry;
			else if (com[i - 1][j - 1].size() > com[i - 1][j].size())	com[i][j].back() = com[i - 1][j - 1].back() + carry;
			else if (carry)												com[i][j].push_back(1);
		}
	}


	cout << com[n][m][com[n][m].size() - 1];
	cout << setfill('0');
	for (int i = com[n][m].size() - 2; i >= 0; i--)
		cout << setw(18) << com[n][m][i];
}
/*
  0  1  2  3  4  5  6
0 1
1 1  1 
2 1  2  1
3 1  3  3  1
4 1  4  6  4  1
5 1  5  10 10 5  1
6 1  6  15 20 15 6  1
*/