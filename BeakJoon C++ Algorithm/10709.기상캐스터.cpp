/// 10709.기상캐스터

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <vector <int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int h, w;
	cin >> h >> w;
	ans.resize(h, vector<int>(w, -1));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char input;
			cin >> input;
			if (input == 'c')
				ans[i][j] = 0;
		}
	}
	
	for (int i = 0; i < h; i++) {
		cout << ans[i][0];
		for (int j = 1; j < w; j++) {
			if (ans[i][j - 1] != -1 && ans[i][j] != 0) {
				ans[i][j] = ans[i][j - 1] + 1;
			}
			cout << ' ' <<ans[i][j];
		}
		cout << endl;
	}
}