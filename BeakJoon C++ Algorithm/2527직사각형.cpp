/// 2527직사각형

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Ret {
public:
	int x1, y1, x2, y2;
	Ret() {
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}
	Ret(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};

Ret getIntersection(Ret, Ret);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int t = 0; t < 4; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Ret a(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		Ret b(x1, y1, x2, y2);
		Ret c = getIntersection(a, b);
		if (c.x1 == 0 && c.y1 == 0) cout << "d\n";
		else if (c.x1 == c.x2) {
			if (c.y1 == c.y2)		cout << "c\n";
			else					cout << "b\n";
		}
		else if (c.y1 == c.y2)		cout << "b\n";
		else						cout << "a\n";
	}
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