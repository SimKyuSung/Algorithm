/// 1940. ����! RCī!

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, d = 0, v = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int cmd, a;	// ���������� a�ΰ�?
			cin >> cmd;
			if (cmd) {
				cin >> a;
				if (cmd == 2)
					a = -a;
				v += a;
			}
			if (v < 0)
				v = 0;
			d += v;
		}

		cout << '#' << t << ' ' << d << '\n';
	}
}

/*
s = v * t
v = a * t
*/