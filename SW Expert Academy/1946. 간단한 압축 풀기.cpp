/// 1946. 간단한 압축 풀기

#include <iostream>

using namespace std;

char output[200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, index = 0;
		char c;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> c >> m;
			while (m--)
				output[index++] = c;
		}

		cout << '#' << t;
		for (int i = 0; i < index; i++) {
			if (i % 10 == 0)
				cout << '\n';
			cout << output[i];
		}
		cout << '\n';
	}
}