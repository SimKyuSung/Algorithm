#include <iostream>
#include <memory.h>

using namespace std;

char star[6562][6562];

void starMaker(int n, int w, int h) {
	if (n == 1) {
		star[w][h] = '*';
		return;
	}
	n = n / 3;

	for (int i = 0, y = w; i < 3; i++, y += n) {
		for (int j = 0, x = h; j < 3; j++, x += n) {
			if (i == 1 && j == 1) continue;
			starMaker(n, x, y);
		}
	}
}
int main()
{
	int N;
	cin >> N;
	memset(star, ' ', sizeof(star));
	starMaker(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << star[i][j];
		cout << endl;
	}
}
