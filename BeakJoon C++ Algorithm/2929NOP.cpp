// 2929NOP

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string cmd;
	int index = 0, nop = 0;
	cin >> cmd;
	for (int i = 0; i < cmd.length(); i++)
		if (cmd[i] < 'a' && (i + nop) % 4 != 0)
			nop = nop + 4 - ((i + nop) % 4);
	printf("%d\n", nop);
}
