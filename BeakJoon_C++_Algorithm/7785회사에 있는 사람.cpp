/// 7785회사에 있는 사람

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector < pair <string, pair <int, bool> > > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		string nameLog, cmdLog;
		cin >> nameLog >> cmdLog;
		v[i].first = nameLog;
		v[i].second.first = i;
		v[i].second.second = cmdLog[0] == 'e';
	}

	sort(v.begin(), v.end());
	string tmpName = "";
	for (int i = n - 1; i > -1; i--) {
		//cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
		if (tmpName != v[i].first) {
			tmpName = v[i].first;
			if (v[i].second.second)
				cout << v[i].first << "\n";
		}
	}
}