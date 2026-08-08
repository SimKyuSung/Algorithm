/// 5373.큐빙

#include <iostream>
#include <string>
#include <memory.h>

#define endl '\n'

using namespace std;

void solve();
void move(int, int, int, bool);
void rotate(bool);
void spin(bool, bool, bool, bool);

struct Cube {
	char surface[6];
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}


// U, D, F, B, L, R
// +CW, -CCW
/* init
U = w
D = y
F = r
B = o
L = g
R = b
*/

char color[] = "wyrogb";
Cube cube[3][3][3];

void solve() {
	// init;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				for (int c = 0; c < 6; c++)
					cube[i][j][k].surface[c] = color[c];
		}
	}

	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		bool cw = cmd[1] == '+';
		switch (cmd[0])
		{
		case 'U':
			move(0, 1, 1, cw);
			break;
		case 'D':
			move(2, 1, 1, !cw);
			break;
		case 'F':
			move(1, 2, 1, cw);
			break;
		case 'B':
			move(1, 0, 1, !cw);
			break;
		case 'L':
			move(1, 1, 0, cw);
			break;
		case 'R':
			move(1, 1, 2, !cw);
			break;
		default:
			break;
		}

		//for (int c = 0; c < 6; c++) {
		//	for (int i = 0; i < 3; i++) {
		//		for (int j = 0; j < 3; j++)
		//			cout << cube[0][i][j].surface[c];
		//		cout << endl;
		//	}
		//	cout << endl;
		//}

	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << cube[0][i][j].surface[0];
		cout << endl;
	}

	//for (int c = 0; c < 6; c++) {
	//	for (int i = 0; i < 3; i++) {
	//		for (int j = 0; j < 3; j++)
	//			cout << cube[0][i][j].surface[c];
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
}

Cube tmp[3][3], tmp2;
void move(int z, int y, int x, bool d) {
	if (z != 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				tmp[i][j] = cube[z][i][j];
		}
		rotate(d);
		spin(1, 0, 0, d);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cube[z][i][j] = tmp[i][j];
		}

	}
	else if (y != 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				tmp[i][j] = cube[i][y][j];
		}
		rotate(d);
		spin(0, 1, 0, d);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cube[i][y][j] = tmp[i][j];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				tmp[i][j] = cube[i][j][x];
		}
		rotate(d);
		spin(0, 0, 1, d);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cube[i][j][x] = tmp[i][j];
		}
	}
}

void rotate(bool d) {
	// cw
	if (d) {
		tmp2 = tmp[0][0];
		tmp[0][0] = tmp[2][0];
		tmp[2][0] = tmp[2][2];
		tmp[2][2] = tmp[0][2];
		tmp[0][2] = tmp2;

		tmp2 = tmp[0][1];
		tmp[0][1] = tmp[1][0];
		tmp[1][0] = tmp[2][1];
		tmp[2][1] = tmp[1][2];
		tmp[1][2] = tmp2;
	} else {	// ccw
		tmp2 = tmp[0][0];
		tmp[0][0] = tmp[0][2];
		tmp[0][2] = tmp[2][2];
		tmp[2][2] = tmp[2][0];
		tmp[2][0] = tmp2;

		tmp2 = tmp[0][1];
		tmp[0][1] = tmp[1][2];
		tmp[1][2] = tmp[2][1];
		tmp[2][1] = tmp[1][0];
		tmp[1][0] = tmp2;
	}
}

void spin(bool z, bool y, bool x, bool d) {
	if (z) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int ttmp = tmp[i][j].surface[3];
				if (d) {
					tmp[i][j].surface[3] = tmp[i][j].surface[4];
					tmp[i][j].surface[4] = tmp[i][j].surface[2];
					tmp[i][j].surface[2] = tmp[i][j].surface[5];
					tmp[i][j].surface[5] = ttmp;
				}
				else {
					tmp[i][j].surface[3] = tmp[i][j].surface[5];
					tmp[i][j].surface[5] = tmp[i][j].surface[2];
					tmp[i][j].surface[2] = tmp[i][j].surface[4];
					tmp[i][j].surface[4] = ttmp;
				}
			}
		}
	}
	else if (y) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int ttmp = tmp[i][j].surface[0];
				if (d) {
					tmp[i][j].surface[0] = tmp[i][j].surface[4];
					tmp[i][j].surface[4] = tmp[i][j].surface[1];
					tmp[i][j].surface[1] = tmp[i][j].surface[5];
					tmp[i][j].surface[5] = ttmp;
				}
				else {
					tmp[i][j].surface[0] = tmp[i][j].surface[5];
					tmp[i][j].surface[5] = tmp[i][j].surface[1];
					tmp[i][j].surface[1] = tmp[i][j].surface[4];
					tmp[i][j].surface[4] = ttmp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int ttmp = tmp[i][j].surface[0];
				if (d) {
					tmp[i][j].surface[0] = tmp[i][j].surface[3];
					tmp[i][j].surface[3] = tmp[i][j].surface[1];
					tmp[i][j].surface[1] = tmp[i][j].surface[2];
					tmp[i][j].surface[2] = ttmp;
				}
				else {
					tmp[i][j].surface[0] = tmp[i][j].surface[2];
					tmp[i][j].surface[2] = tmp[i][j].surface[1];
					tmp[i][j].surface[1] = tmp[i][j].surface[3];
					tmp[i][j].surface[3] = ttmp;
				}
			}
		}
	}
}

/*

00	0
01	1
10	1
11	0

*/


/*
0+- 
	3
4	0	5
	2
	1
-		 +
<- 3524 ->
   0123


	0
4	2	5
	1
	3

표면적
9 * 6 = 54

부피
3 * 3 * 3 = 27


*/