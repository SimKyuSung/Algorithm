// 2941LJESNJAK

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string line;
	int ans = 0;
	cin >> line;
	bool c, d, l, n, s, z, dz;
	c = d = l = n = s = z = dz = false;

	for (int i = 0; i < line.length(); i++) {
		char tmp = line[i];

		if (c && (tmp == '=' || tmp == '-'))
			ans--;		// c=, c-
		if (d && (tmp == '-'))
			ans--;		// d-
		if (l && (tmp == 'j'))
			ans--;		//lj
		if (n && (tmp == 'j'))
			ans--;		// nj
		if (s && (tmp == '='))
			ans--;		// s=
		if (z && (tmp == '='))
			ans--;		// z=
		if (dz && (tmp == '='))
			ans--;

		c = l = n = s = z = dz = false;
		if (tmp == 'c') {
			c = true;
			d = l = n = s = z = dz = false;
		}
		else if (tmp == 'd') {
			d = true;
			c = l = n = s = z = dz = false;
		}
		else if (tmp == 'l') {
			l = true;
			c = d = n = s = z = dz = false;
		}
		else if (tmp == 'n') {
			n = true;
			c = d = l = s = z = dz = false;
		}
		else if (tmp == 's') {
			s = true;
			c = d = l = n = z = dz = false;
		}
		else if (tmp == 'z') {
			z = true;
			if (d)		dz = true;
			else		dz = false;
			c = d = l = n = s = false;
		}
		else
			c = d = l = n = s = z = dz = false;

		ans++;
	}
	cout << ans << endl;
}