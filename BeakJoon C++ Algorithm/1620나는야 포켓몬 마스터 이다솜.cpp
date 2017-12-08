/// 1620나는야 포켓몬 마스터 이다솜

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char pokemon[100001][25];
map <string, int> t;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", pokemon[i]);
		t[pokemon[i]] = i;
	}

	while (m--) {
		char input[25] = { '\0' };
		scanf("%s", input);
		// 1. 알파벳일 경우 2.숫자일 경우
		if ('A' <= input[0] && input[0] <= 'Z')
			cout << t[input] << "\n";
		else {
			// 문자열을 숫자로 치환!
			int j = 0, num = 0;
			while (input[j] != '\0') {
				num *= 10;
				num += (input[j++] - '0');
			}
			cout << pokemon[num] << "\n";
		}
	}
}