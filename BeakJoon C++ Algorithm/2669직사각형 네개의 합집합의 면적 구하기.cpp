/// 2669직사각형 네개의 합집합의 면적 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Ret {
public:
	double x1, y1, x2, y2;
	Ret(double x1, double y1, double x2, double y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	double getArea() {
		return (x2 - x1) * (y2 - y1);
	}
};

vector <Ret> a[4];

Ret getIntersection(Ret, Ret);
void intersection(int, int, int, Ret);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	double x1, y1, x2, y2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		a[0].push_back(Ret(x1, y1, x2, y2));
	}
	Ret tmp(0, 0, 100, 100);
	intersection(n, -1, 0, tmp);
	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			// cout << a[i][j].x1 << " " << a[i][j].y1 << " " << a[i][j].x2 << " " << a[i][j].y2 << endl;
			if (i % 2)	ans -= a[i][j].getArea();
			else		ans += a[i][j].getArea();
		}
	}
	cout << ans;
}

Ret getIntersection(Ret a, Ret b) {
	Ret c(0, 0, 0, 0);
	if (a.x1 > b.x2 || a.x2 < b.x1 || a.y1 > b.y2 || a.y2 < b.y1)
		return c;
	c.x1 = max(a.x1, b.x1);
	c.y1 = max(a.y1, b.y1);
	c.x2 = min(a.x2, b.x2);
	c.y2 = min(a.y2, b.y2);
	return c;
}

void intersection(int n, int index, int counter, Ret tmp) {
	if (counter > 1) a[counter - 1].push_back(tmp);
	if (n == counter)
		return;
	while (++index < n)
		intersection(n, index, counter + 1, getIntersection(tmp, a[0][index]));
}
/*

a, b, c, d의 합집합의 면적

ab      = a + b - a^b
abc      = a + b + c - a^b - a^c - b^c + a^b^c
= (a + b - a^b)c
= (a + c - a^c)   + (b + c - b^c) - (a^b + c - a^b^c)
abcd   = (a + b + c - a^b - a^c - b^c + a^b^c)d

a + d - a^d
b + d - b^d
c + d - c^d
-(a^b + d - a^b^d)
-(a^c + d - a^c^d)
-(b^c + d - b^c^d)
a^b^c + d - a^b^c^d

홀수 -> +
짝수 -> -

a + b + c + d
- ab - ac - ad - bc - bd - cd
+ abc + abd + acd + bcd
-abcd

*/