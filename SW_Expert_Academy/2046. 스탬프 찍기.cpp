/// 2046. ½ºÅÆÇÁ Âï±â

#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	char *s = new char[n + 1]();
	memset(s, '#', sizeof(char) * n);
	cout << s << endl;
}