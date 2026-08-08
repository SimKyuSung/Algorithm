/// 1296µ•¿Ã∆Æ

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int a1[128];
int a2[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string omg;

	int n, ansPos = 0;
	int ans = 0;

	cin >> omg >> n;
	vector <string> name(n);
	for (int i = 0; i < omg.length(); i++)
		a1[omg[i]]++;
	for (int i = 0; i < n; i++)
		cin >> name[i];
	sort(name.begin(), name.end());

	for (int i = 0; i < n; i++) {

		memset(a2, 0, sizeof(a2));
		for (int j = 0; j < name[i].length(); j++)
			a2[name[i][j]]++;

		int l = a1['L'] + a2['L'];
		int o = a1['O'] + a2['O'];
		int v = a1['V'] + a2['V'];
		int e = a1['E'] + a2['E'];
		int pos = (((l + o) * (l + v) * (l + e)) % 100 * ((o + v) * (o + e) * (v + e)) % 100) % 100;
		if (pos > ansPos) {
			ans = i;
		}
	}
	cout << name[ans] << '\n';
}