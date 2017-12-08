// 10815Card

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, input;
	cin >> n;
	map<int, bool> sang;
	while (n--) {
		cin >> input;
		sang.insert({ input, true });
	}
	cin >> m;
	while (m--) {
		cin >> input;
		if (sang[input])
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
}