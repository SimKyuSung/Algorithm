/// 1063킹

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, k;
	int n;
	cin >> k >> s >> n;
	int kx = k[0] - 'A',
		ky = k[1] - '1',
		sx = s[0] - 'A',
		sy = s[1] - '1';

	while (n--) {
		string line;
		cin >> line;

		int moveX = 0, moveY = 0;
		for (int i = 0; i < line.length(); i++) {
			switch (line[i])
			{
			case 'R':
				moveX += 1;
				break;
			case 'L':
				moveX -= 1;
				break;
			case 'B':
				moveY -= 1;
				break;
			case 'T':
				moveY += 1;
				break;
			}
		}
		int tx = kx + moveX;
		int ty = ky + moveY;
		// 1. 움직이려고 하는 곳에 돌이 있는 경우
		if (tx == sx && ty == sy) {
			// 1-1 돌을 움직이는데 맵 안쪽으로만 옮김
			tx = sx + moveX;
			ty = sy + moveY;
			if (tx < 0 || 7 < tx || ty < 0 || 7 < ty)
				continue;
			kx = sx;
			ky = sy;
			sx = tx;
			sy = ty;
		}
		// 2. 움직이려고 하는 곳이 맵 밖인 경우
		else if (tx < 0 || 7 < tx || ty < 0 || 7 < ty)
			continue;
		else {
			kx = tx;
			ky = ty;
		}
	}
	cout << char(kx + 'A') << ky + 1 << endl;
	cout << char(sx + 'A') << sy + 1 << endl;
}

/*
8
7
6
5
4
3
2
1
  A  B  C  D  E  F  G  H
*/