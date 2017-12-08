/// 1064����纯��

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

double lineLenth(int ,int ,int ,int);
double extend_sqrt(double, double);

int main()
{
	double x[3], y[3];
	int i = 3;
	while (i--)
		cin >> x[i] >> y[i];

	// 1�� �˻� 
	double gradient[2] = {numeric_limits<double>::max(), numeric_limits<double>::max() };

	if (x[0] != x[1])
		gradient[0] = (y[0] - y[1]) / (x[0] - x[1]);
	if (x[0] != x[2])
		gradient[1] = (y[0] - y[2]) / (x[0] - x[2]);

	if (gradient[0] == gradient[1] || gradient[0] == gradient[1] * -1) {
		cout << -1 << endl;
		return 0;
	}

	// 1���� �ƴ϶�� 
	double l[3];
	l[0] = lineLenth(x[0], y[0], x[1], y[1]);
	l[1] = lineLenth(x[2], y[2], x[1], y[1]);
	l[2] = lineLenth(x[0], y[0], x[2], y[2]);
	double a = max(l[0], max(l[1], l[2]));
	double b = min(l[0], min(l[1], l[2]));

	cout << fixed;
	cout.precision(16);
	a = extend_sqrt(a, sqrt(a));
	b = extend_sqrt(b, sqrt(b));
	cout << 2 * (a - b) << endl;
	return 0;
}

double lineLenth(int x1, int y1, int x2, int y2) {
	double xx = x1 - x2;
	double yy = y1 - y2;
	return xx * xx + yy * yy;
}
double extend_sqrt(double input, double x) {
	for (int i = 0; i < 10; i++)
		x = (x + (input / x)) / 2;
	return x;
}

/*
 �� 2���� ������ �ʴ´� ccw�� ���� ���ؼ� 2�� �Ѵ�.
 ��� ���̰� �ƴϳ�...

 ���̰� A B C �϶�
 
 �ѷ� ���� ����� ��
 2(A + B), 2(A + C), 2(B + C)

 

*/