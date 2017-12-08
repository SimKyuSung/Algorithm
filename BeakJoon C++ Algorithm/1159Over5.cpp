// 1159Over5

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string name;
	vector<int> alpha(26, 0);
	cin >> n;
	while (n--) {
		cin >> name;
		alpha[name[0] - 'a']++;
	}
	n = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 4) {
			printf("%c", i + 'a');
			n++;
		}
	}
	if (n)	printf("\n");
	else	printf("PREDAJA\n");
}