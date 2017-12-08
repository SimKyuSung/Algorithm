#include <iostream>
#include <cstdio>

using namespace std;

int area2D(int*, int*, int);
/* int area3D(int*, int*, int*, int); */

int main() {
	ios::sync_with_stdio(false);

	int x[1000], y[1000], z[1000];
	int s;
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	
	s = area2D(x, y, 3);
	if (s > 0)
		s = 1;
	else if (s < 0)
		s = -1;
	else
		s = 0;
	
	printf("%d\n", s);
}

/*
사선 공식
	S = (1/2) * |x1 x2 x3 x4 ; y1 y2 y3 y4 ; z1 z2 z3 z4|
*/

int area2D(int *x, int *y, int n) {
	int temp1 = 0;
	int temp2 = 0;
	x[n] = x[0];
	y[n] = y[0];
	for (int i = 0; i < n; i++) {
		temp1 += x[i] * y[i + 1];
		temp2 += x[i + 1] * y[i];
	}
	return (temp1 - temp2) / 2;
}

/*
int area3D(int *x, int *y, int *z, int n) {
	int temp1 = 0;
	int temp2 = 0;
	x[n] = x[0];
	x[n + 1] = x[1];
	
	y[n] = y[0];
	y[n + 1] = y[1];

	z[n] = z[0];
	z[n + 1] = z[1];

	for (int i = 0; i < n; i++) {
		temp1 += x[i] * y[i + 1] * z[i + 2];
		temp2 += x[i + 2] * y[i + 1] * z[i];
	}
	return temp1 - temp2;
}
*/