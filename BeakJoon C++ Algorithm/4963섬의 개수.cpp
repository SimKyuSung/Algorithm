/// 4963섬의 개수

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

// 인덱스 에러뛰어 넘기
int w, h;
int ls[52][52];

// 체크표시
void function(int, int);

int main()
{
	ios::sync_with_stdio(false);
	while (1) {
		int ans = 0;
		cin >> w >> h;
		memset(ls, 0, sizeof(ls));
		if (w == 0 && h == 0)	break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> ls[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (ls[i][j]) {
					ans++;
					function(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
}

void function(int y, int x) {
	ls[y][x] = 0;
	for (int i = y - 1; i < y + 2; i++) {
		for (int j = x - 1; j < x + 2; j++) {
			if (ls[i][j]) function(i, j);
		}
	}
}