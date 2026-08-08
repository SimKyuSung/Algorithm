// 1297TV

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	double diagnalLen, height_r, width_r, rate;
	// input precondition
	// width > heught
	cin >> diagnalLen >> height_r >> width_r;
	rate = diagnalLen * diagnalLen / (height_r * height_r + width_r *width_r);

	cout << int(height_r * sqrt(rate)) << " " << int(width_r * sqrt(rate)) << "\n";
}