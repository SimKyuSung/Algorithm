/// 1208. [S/W 문제해결 기본] 1일차 - Flatten

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int box[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;
	//cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, top = 0, bottom = 100;
		memset(box, 0, sizeof(box));
		cin >> n;
		for (int i = 0; i < 100; i++) {
			int input;
			cin >> input;
			box[input]++;
			top = max(top, input);
			bottom = min(bottom, input);
		}
		while (n-- && top - bottom > 1) {
			box[top]--;
			box[top - 1]++;
			box[bottom]--;
			box[bottom + 1]++;
			while (box[top] == 0) {
				top--;
			}
			while (box[bottom] == 0) {
				bottom++;
			}
		}

		cout << '#' << t << ' ' << top - bottom << '\n';
	}
}