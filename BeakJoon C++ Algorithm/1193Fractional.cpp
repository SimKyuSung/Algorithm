#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	int m = 1, c = 1;
	bool right = true;
	cin >> n;
	// 위 아래로 왔다갔다하면서 노다가로 분석
	for (int i = 1; i < n; i++) {
		if (right) {
			m++;
			c--;
			if (c == 0) {
				c = 1;
				right = false;
			}
		}
		else {
			m--;
			c++;
			if (m == 0) {
				m = 1;
				right = true;
			}
		}
	}
	printf("%d/%d\n", c, m);
}