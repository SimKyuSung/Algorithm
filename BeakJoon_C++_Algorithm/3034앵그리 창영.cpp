/// 3034앵그리 창영

#include <iostream>

using namespace std;

int main()
{
	int n, w, h, a, b;
	cin >> n >> w >> h;
	b = w * w + h * h;
	while (n--) {
		cin >> a;
		if (b < a * a)	cout << "NE\n";
		else			cout << "DA\n";
	}

}