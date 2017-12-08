/// 1063ŷ

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
		// 1. �����̷��� �ϴ� ���� ���� �ִ� ���
		if (tx == sx && ty == sy) {
			// 1-1 ���� �����̴µ� �� �������θ� �ű�
			tx = sx + moveX;
			ty = sy + moveY;
			if (tx < 0 || 7 < tx || ty < 0 || 7 < ty)
				continue;
			kx = sx;
			ky = sy;
			sx = tx;
			sy = ty;
		}
		// 2. �����̷��� �ϴ� ���� �� ���� ���
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