/// 1228. [S/W 문제해결 기본] 8일차 - 암호문1

#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

list <int> code;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//ifstream cin("input.txt");
	int testCase = 10;

	for (int t = 1; t <= testCase; t++) {
		code.clear();

		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			code.push_back(s);
		}
		cin >> m;

		list <int>::iterator itor = code.begin();

		for (int i = 0; i < m; i++) {
			char cmd;
			int x, y, s;
			cin >> cmd;
			if (cmd == 'I') {
				cin >> x >> y;
				itor = code.begin();
				for (int j = 0; j < x; j++)
					itor++;
				for (int j = 0; j < y; j++) {
					cin >> s;
					code.insert(itor, s);
				}
			}
			else if (cmd == 'D') {
				cin >> x >> y;
				itor = code.begin();
				for (int j = 0; j < x; j++)
					itor++;
				for (int j = 0; j < y; j++)
					code.erase(itor++);
			}
			else if (cmd == 'A') {
				cin >> y;
				for (int j = 0; j < y; j++) {
					cin >> s;
					code.push_back(s);
				}
			}
		}

		itor = code.begin();
		cout << '#' << t;
		for (int i = 0; i < 10; i++)
			cout << ' ' << *itor++;
		cout << '\n';
	}
}