/// 14890.경사로

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int n, l;
vector <vector <int> > map1, map2;
int function(vector <vector <int> >);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> l;
	map1.resize(n, vector<int>(n));
	map2.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
			map2[j][i] = map1[i][j];
		}
	}

	int ans = n * 2;
	cout << ans - function(map1) - function(map2) << endl;
}

int function(vector <vector <int> > map) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int x = map[i][0], counter = 1;
		for (int j = 1; j < n; j++) {
			// 1 + 오르막
			if (x + 1 == map[i][j] && counter >= l) {
				counter = 1;
				x = map[i][j];
			}
			// 1 - 내리막
			else if (x - 1 == map[i][j]) {
				x = map[i][j];
				bool flag = j + l <= n;
				for (int k = 1; k < l; k++) {
					if (x != map[i][j + k])
						flag = false;
				}
				counter = 0;
				j += l - 1;
				if (!flag) {
					ret++;
					break;
				}
			}
			// 평지
			else if (map[i][j] == x) {
				counter++;
			}
			// 응?
			else {
				ret++;
				break;
			}
		}
	}
	return ret;
}