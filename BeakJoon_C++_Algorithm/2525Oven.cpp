// 2525Oven

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int a, b, c;
	int hour, minute;
	cin >> a >> b;
	cin >> c;
	minute = b + c;
	hour = a + minute / 60;
	minute = minute % 60;
	hour = hour % 24;
	cout << hour << " " << minute << '\n';
}