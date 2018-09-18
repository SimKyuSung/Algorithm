/// 15552.ºü¸¥ A+B

#include <iostream>
#include <cstdio>
#include <memory.h>

#define endl '\n'

using namespace std;

const int bufSize = 4000000;
char i[bufSize], o[5], tmp[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 0, p = 0;
	fread(i, 1, bufSize, stdin);
	while (i[p++] != '\n')
		t = t * 10 + (i[p - 1] - '0');
	while (t--) {
		int a = 0, b = 0;
		while (i[p++] != ' ') {
			a = a * 10 + (i[p - 1] - '0');
			if (p == bufSize) {
				p = 0;
				fread(i, 1, bufSize, stdin);
			}
		}
		while (i[p++] != '\n') {
			b = b * 10 + (i[p - 1] - '0');
			if (p == bufSize) {
				p = 0;
				fread(i, 1, bufSize, stdin);
			}
		}
		a += b;

		int cy = 0, po = 0;
		//memset(o, 0, 5);
		while (a) {
			tmp[cy++] = (a % 10) + '0';
			a /= 10;
		}
		while (cy--)
			o[po++] = tmp[cy];
		o[po++] = '\n';
		fwrite(o, 1, po, stdout);
	}
}