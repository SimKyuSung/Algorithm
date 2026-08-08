/// 14584.암호 해독

#include <iostream>
#include <string>

using namespace std;

string a, b[20];
char c[103];

int main() {
	int i, j, n;
	int k, l;
	cin >> a >> n;
	for (i = 0; i < n; i++)
		cin >> b[i];
	for (i = 0; i < 26; i++) {
		for (j = 0; j < a.length(); j++)
			c[j] = (a[j] - 97 + i) % 26 + 97;
		for (j = 0; j < n; j++) {
			for (k = 0; k < a.length(); k++) {
				if (b[j][0] == c[k]) {
					for (l = 0; l < b[j].length(); l++) {
						if (c[k + l] != b[j][l])
							break;
					}
					if (l == b[j].length()) {
						cout << c << endl;
						return 0;
					}
				}
			}
		}
	}
}