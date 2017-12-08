// 2605Alram

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int h, m;
	int my_hour, my_minute;
	cin >> h >> m;
	my_minute = m - 45;
	my_hour = h;
	if (my_minute < 0) {
		my_hour--;
		my_minute += 60;
	}
	if (my_hour < 0)
		my_hour += 24;
	cout << my_hour % 24 << " " << my_minute % 60 << endl;
}

/*
10 10
9 25
*/